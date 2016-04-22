CC=gcc
CLFLAGS=-Iinclude -W -Wall -ansi -pedantic
LDFLAGS=-lwiringPi
EXEC=main

all: $(EXEC)
main: build/main.o build/barrier.o
	gcc -o $@ $^ $(LDFLAGS) -Iinclude 

build/main.o: src/main.c 
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS)

build/barrier.o: src/barrier.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS) 

clean:
	rm build/*.o

