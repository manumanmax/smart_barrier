#ifndef BARRIER_H
#define BARRIER_H

#define UP 1
#define DOWN 0
#define RAISED 96 
#define SET 55
#define PIN 1

typedef struct Barrier{
	int position;	
} Barrier;

void setupBarrier(int periode);
void moveBarrier(Barrier* b);

#endif
