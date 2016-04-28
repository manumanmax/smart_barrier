#ifndef STATE_H
#define STATE_H
#include <stdlib.h>
#include <assert.h>
#include "io.h"

/*
* The module contains the basic functions and structures
* used to define a state and the related state transition function and 
* output function. 
*/

//Type of a state identifier
typedef unsigned char state_id_t;

/*
*  Type of state transition function
*  The function requires the following parameters:
*   - input vector to read the current value
*   - state vector used to return the next state reference
*   - free parameter used to pass additional information 
*/
typedef void* (*next_state_fun_t)(input_t* inputs, void* states, void* par);

/*
* Type of output function 
* The function requires the following parameters:
*   - output vector to set the new output values  
*   - free parameter used to pass additional information 
*/
typedef void (*get_output_fun_t)(output_t* outputs, void* par);

//Structure of a generic state
struct state_s
{
	state_id_t id;                  //State identifier 
	next_state_fun_t next_state;    //Next state function
	get_output_fun_t update_output; //Output function
};

//Type of a state
typedef struct state_s state_t; 

#endif /* STATE_H */