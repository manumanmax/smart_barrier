#ifndef BARRIER_H
#define BARRIER_H

typedef enum Position Position;
enum Position
{
	UP,DOWN
};

typedef Struct Barrier{
	int startAngle;
	Position pos;	
} Barrier;

void raiseBarrier();
void setupBarrier();

#endif
