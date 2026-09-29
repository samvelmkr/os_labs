CXX=g++
CXXFLAGS= -Wall -Wextra

TARGET=main
SRC=main.cpp

all: ${TARGET}

run: ${TARGET}
	./${TARGET}

main.o: main.cpp
	g++ main.cpp -c -o main.o

${TARGET}: ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o ${TARGET}

clean:
	rm -f ${TARGET} *.o *.s

