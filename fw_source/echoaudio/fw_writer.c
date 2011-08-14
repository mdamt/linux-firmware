/*
 *  ALSA driver for Echoaudio soundcards.
 *  Copyright (C) 2003-2004 Giuliano Pochini <pochini@shiny.it>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


char *next_number(char *c)
{
	while (1) {
		c++;
		if (*c==0 || *c == '}')
			return NULL;
		if (c[0]=='0' && c[1]=='x')
			return c;
	}
}



int write_fw(const char *dest, const char *src)
{
	uint16_t d16;
	uint8_t d8;
	int fd;
	struct stat stbuf;
	char *buf, *c;

	if ((fd = open(src, O_RDONLY)) < 0) {
		printf("%s: %s\n", src, strerror(errno));
		exit(errno);
	}
	if (fstat(fd, &stbuf) < 0) {
		printf("%s: %s\n", src, strerror(errno));
		exit(errno);
	}
	if (!(buf = malloc(stbuf.st_size + 1))) {
		puts("Out of memory.");
		exit(ENOMEM);
	}
	if (read(fd, buf, stbuf.st_size) < stbuf.st_size) {
		puts("Read error.");
		exit(EIO);
	}
	close(fd);
	buf[stbuf.st_size] = 0;

	if ((fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
		printf("%s: %s\n", dest, strerror(errno));
		exit(errno);
	}
	if ((c = strstr(buf, "u8 ")) || (c = strstr(buf, "BYTE ")) || (c = strstr(buf, "char "))) {
		while (c = next_number(c)) {
			d8 = strtol(c, NULL, 16);
			if (write(fd, &d8, 1) < 1) {
				printf("Error writing %s\n", dest);
				exit(EIO);
			}
		}
	} else if ((c = strstr(buf, "u16 ")) || (c = strstr(buf, "WORD "))) {
		while (c = next_number(c)) {
			d16 = strtol(c, NULL, 16);
			if (write(fd, &d16, 2) < 2) {
				printf("Error writing %s\n", dest);
				exit(EIO);
			}
		}
	} else {
		printf("%s currupted ?\n", src);
		exit(EINVAL);
	}
	close(fd);
	free(buf);

	return 0;
}



int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Syntax: %s <source> <destination>\n", argv[0]);
		exit(0);
	}
	write_fw(argv[2], argv[1]);
	return 0;
}
