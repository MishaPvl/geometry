.PHONY: all clean

all: bin/geometry


bin/geometry: build/src/main.o build/src/circle.o
	gcc -Wall -Werror build/src/main.o build/src/circle.o -o bin/geometry -lm

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/circle.o: src/geometry.c
	gcc -Wall -Werror -c src/geometry.c -o build/src/circle.o