CC=gcc
CLFLAGS=-Iinclude -W -Wall -ansi -pedantic
LDFLAGS=-lwiringPi
EXEC=main

all: $(EXEC)
main: build/barrier.o build/main.o
	gcc -o $@ $^

build/main.o: src/main.c
	gcc -o $@ -c $^ $(CLFLAGS)

build/barrier.o: src/barrier.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS) 

clean:
	rm build/*.o
