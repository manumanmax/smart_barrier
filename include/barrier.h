#ifndef BARRIER_H
#define BARRIER_H

#define UP 1
#define DOWN 0
#define RAISED 96 
#define SET 50
#define PIN 1

typedef struct Barrier{
	int position;	
} Barrier;

void setupBarrier(Barrier* b);
void moveBarrier(Barrier* b);

#endif
