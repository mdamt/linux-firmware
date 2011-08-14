export firmware_dir := $(shell pwd)/..

SUBDIRS = echoaudio

build:
	for dir in $(SUBDIRS) ; do ( cd $$dir ; $(MAKE) all ) ; done

install:
	for dir in $(SUBDIRS) ; do ( cd $$dir ; $(MAKE) install ) ; done

clean:
	for dir in $(SUBDIRS) ; do ( cd $$dir ; $(MAKE) clean ) ; done

update: build install clean
