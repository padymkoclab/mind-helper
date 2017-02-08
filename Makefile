
MAIN_FILE=main.c
TEMPFILE='__tempfile__'
C_STD_VERSION=c11

WARNNING=-Wall -Wextra -Wpedantic
WARNNING=

all: compile

compile: ${MAIN_FILE}
	@ gcc ${WARNNING} -std=${C_STD_VERSION} -o ${TEMPFILE} ${MAIN_FILE} `pkg-config --libs --cflags gtk+-3.0`
	@ ./${TEMPFILE}
	@ rm ${TEMPFILE}
