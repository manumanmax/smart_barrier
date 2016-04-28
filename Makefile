CC=gcc
CLFLAGS=-Iinclude -W -Wall -ansi -pedantic
LDFLAGS=-lwiringPi -lphidget21
EXEC=main

all: $(EXEC)
main: build/main.o build/barrier.o build/rfid.o build/led.o build/sensor.o build/init.o build/mooremachine.o build/park_manager.o
	gcc -o $@ $^ $(LDFLAGS) -Iinclude 

build/main.o: src/main.c 
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS)

build/barrier.o: src/barrier.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS) 
	
build/rfid.o: src/rfid.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS)

build/led.o: src/led.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS)

build/sensor.o: src/sensor.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS)

build/init.o: src/init.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS) 

build/mooremachine.o: src/mooremachine.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS) 

build/park_manager.o: src/park_manager.c
	gcc -o $@ -c $^ $(CLFLAGS) $(LDFLAGS) 

clean:
	rm build/*.o

