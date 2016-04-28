#ifndef MOORE_MACHINE_H
#define MOORE_MACHINE_H
#include <stdbool.h>
#include "state.h"
#include "io.h"

/*
* The module contains the basic functions and structure to 
* realize a Moore Machine.
*/

//Structure of a Moore Machine
struct moore_s
{
	int num_inputs;           //Number of inputs
	int num_states;           //Number of states
	int num_outputs;          //Number of output
	input_t* inputs;          //Input vector
	state_t* states;          //States vector
	output_t* outputs;        //Output vector
	state_t* current_state;   //Reference to the current state
    long long cycle_limit; 	  //Machine cycle time limit
};

//Type of a Moore Machine
typedef struct moore_s moore_t;

/*
* Type of function to add additional steps to the main cycle
* Parameters:
*   - Free parameter
*/
typedef void (*cycle_fun)(void *p);

/*
* Main function to run the machine
* Properties:
*   - Moore Machine
*   - Additional function to run at the beginning of the cycle
*   - Free parameter of the additional cycle function
*/
void run(moore_t* m, cycle_fun run, void* p);

#endif