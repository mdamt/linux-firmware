firmware_files =	\
		loader_dsp.fw \
		darla20_dsp.fw \
		gina20_dsp.fw \
		layla20_dsp.fw \
		layla20_asic.fw \
		darla24_dsp.fw \
		gina24_301_dsp.fw \
		gina24_301_asic.fw \
		gina24_361_dsp.fw \
		gina24_361_asic.fw \
		layla24_dsp.fw \
		layla24_1_asic.fw \
		layla24_2A_asic.fw \
		layla24_2S_asic.fw \
		mona_301_dsp.fw \
		mona_301_1_asic_48.fw \
		mona_301_1_asic_96.fw \
		mona_361_dsp.fw \
		mona_361_1_asic_48.fw \
		mona_361_1_asic_96.fw \
		mona_2_asic.fw \
		mia_dsp.fw \
		echo3g_dsp.fw \
		3g_asic.fw \
		indigo_dsp.fw \
		indigo_io_dsp.fw \
		indigo_iox_dsp.fw \
		indigo_dj_dsp.fw \
		indigo_djx_dsp.fw

all: $(firmware_files)

install: all
	install -d "$(firmware_dir)/ea"
	install -m 0644 $(firmware_files) "$(firmware_dir)/ea/"

clean:
	rm $(firmware_files) fw_writer

$(firmware_files): fw_writer
	./fw_writer DSP/LoaderDSP.c loader_dsp.fw
	./fw_writer DSP/Darla20DSP.c darla20_dsp.fw
	./fw_writer DSP/Gina20DSP.c gina20_dsp.fw
	./fw_writer DSP/Layla20DSP.c layla20_dsp.fw
	./fw_writer ASIC/LaylaASIC.c layla20_asic.fw
	./fw_writer DSP/Darla24DSP.c darla24_dsp.fw
	./fw_writer DSP/Gina24DSP.c gina24_301_dsp.fw
	./fw_writer ASIC/Gina24ASIC.c gina24_301_asic.fw
	./fw_writer DSP/Gina24_361DSP.c gina24_361_dsp.fw
	./fw_writer ASIC/Gina24ASIC_361.c gina24_361_asic.fw
	./fw_writer DSP/Layla24DSP.c layla24_dsp.fw
	./fw_writer ASIC/Layla24_1ASIC.c layla24_1_asic.fw
	./fw_writer ASIC/Layla24_2A_ASIC.c layla24_2A_asic.fw
	./fw_writer ASIC/Layla24_2S_ASIC.c layla24_2S_asic.fw
	./fw_writer DSP/MonaDSP.c mona_301_dsp.fw
	./fw_writer ASIC/Mona1ASIC48.c mona_301_1_asic_48.fw
	./fw_writer ASIC/Mona1ASIC96.c mona_301_1_asic_96.fw
	./fw_writer DSP/Mona361DSP.c mona_361_dsp.fw
	./fw_writer ASIC/Mona1ASIC48_361.c mona_361_1_asic_48.fw
	./fw_writer ASIC/Mona1ASIC96_361.c mona_361_1_asic_96.fw
	./fw_writer ASIC/Mona2ASIC.c mona_2_asic.fw
	./fw_writer DSP/MiaDSP.c mia_dsp.fw
	./fw_writer DSP/Echo3gDSP.c echo3g_dsp.fw
	./fw_writer ASIC/3G_ASIC.c 3g_asic.fw
	./fw_writer DSP/IndigoDSP.c indigo_dsp.fw
	./fw_writer DSP/IndigoIODSP.c indigo_io_dsp.fw
	./fw_writer DSP/IndigoIOxDSP.c indigo_iox_dsp.fw
	./fw_writer DSP/IndigoDJDSP.c indigo_dj_dsp.fw
	./fw_writer DSP/IndigoDJxDSP.c indigo_djx_dsp.fw
