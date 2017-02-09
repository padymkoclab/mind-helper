#! /usr/bin/make -f

# https://github.com/AkselMeola/simple-c-project-template/blob/master/src/Makefile


###########################
# Local paths
###########################

INCLUDES=./include
DATA=./data
SOURCE=./src
VERSION_FILE=./VERSION


###########################
# Shared resources
###########################

SHARED_CFLAGS = \
	-I $(INCLUDES) \
	$(shell pkg-config --libs --cflags gtk+-3.0)


#############################
# Compiler flags
#############################

CC=gcc
C_STD_VERSION=c11
WARNNING=-Wall -Wextra -Wpedantic
# WARNNING=


#############################
# Debug
#############################


MAIN_FILENAME=main.c
MAIN_FILE=$(SOURCE)/$(MAIN_FILENAME)
TEMPFILE='__tempfile__'


all: compile

compile: $(MAIN_FILE)
	@ ${CC} ${WARNNING} -std=${C_STD_VERSION} -o ${TEMPFILE} ${MAIN_FILE} ${SHARED_CFLAGS}
	@ ./${TEMPFILE}
	@ rm ${TEMPFILE}

version:
	@ cat $(VERSION_FILE)

clean:
	@ echo "Not implemented"

docs:
	@ echo "Not implemented"

install:
	@ echo "Not implemented"

licence:
	@ echo "Not implemented"
