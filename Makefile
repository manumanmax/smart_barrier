
main: barrier.o main.o
	gcc -o main main.o barrier.o
main.o: main.c
	gcc -o main.o -c main.c -Wall -ansi -pedantic

barrier.o: barrier.c
	gcc -o barrier.o -c barrier.c -Wall -ansi -pedantic -lwiringPi

clean:
	rm *.o
