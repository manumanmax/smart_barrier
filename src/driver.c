#include "mooremachine.h"
#include "park_manager.h"
#include "init.h"

int main()
{
	moore_t m;
	init_setup();
	initialize(&m);
 	run(&m, begin_cycle, NULL);
}
