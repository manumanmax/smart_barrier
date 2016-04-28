#ifndef STATE_H
#define STATE_H
#include <stdlib.h>
#include <assert.h>
#include "io.h"

//Type of a state identifier
typedef unsigned char state_id_t;

typedef void* (*next_state_fun_t)(input_t* inputs, void* states, void* par);

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