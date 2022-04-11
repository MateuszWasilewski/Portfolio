CC_CPP = g++
CC_JAVA = javac

CFLAGS_CPP = -Wall -Wextra -g -O3 -std=c++17
CFLAGS_JAVA =

SRC_CPP = $(wildcard src_cpp/*.cpp)
SRC_JAVA = ${wildcard src_java/*.java}
ZIP_FILES = tests src_cpp src_java makefile README.md run.sh
ZIP_FILE = speed.zip

all: src_java/Main.class main_cpp

main_cpp: ${SRC_CPP}
	${CC_CPP} ${CFLAGS_CPP} -o main_cpp ${SRC_CPP}

src_java/Main.class: ${SRC_JAVA}
	${CC_JAVA} ${CFLAGS_JAVA} ${SRC_JAVA}

clean:
	rm -f ${subst .java,.class,${SRC_JAVA}} main_cpp

zip: ${ZIP_FILE}

${ZIP_FILE}: ${ZIP_FILES}
	zip ${ZIP_FILE} ${ZIP_FILES}