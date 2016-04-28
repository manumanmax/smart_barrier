#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "state.h"
#include "io.h"
#include "mooremachine.h"
#include "park_manager.h"


static char stdin_buffer[256];
static state_t states[NUM_OF_STATES];
static input_t inputs[NUM_OF_INPUTS];
static output_t outputs[NUM_OF_OUTPUTS];

static void init_machine(moore_t* m);
static void init_input(input_id_t id, pin_t pin, read_in read);
static void init_output(output_id_t id, pin_t pin, write_out write);
static void init_state(state_id_t id, next_state_fun_t next, get_output_fun_t out);

static void* standby_next_state(input_t* inputs, void* states, void* par);
static void* errorcard_next_state(input_t* inputs, void* states, void* par);
static void* validcard_next_state(input_t* inputs, void* states, void* par);
static void* carunderbarrier_next_state(input_t* inputs, void* states, void* par);

static void standby_output(output_t* outputs, void* par);
static void errorcard_output(output_t* outputs, void* par);
static void validcard_output(output_t* outputs, void* par);
static void carunderbarrier_output(output_t* outputs, void* par);

void initialize(moore_t* m)
{
  int i;
  
  //Intializing inputs
  init_input(IN_BEFORE_SENSOR, IN_BEFORE_SENSOR_PIN, read_input);
  init_input(IN_RFID, IN_RFID_PIN, read_input);
  init_input(IN_AFTER_SENSOR, IN_AFTER_SENSOR_PIN, read_input);

  //Initializing outputs
  init_output(OUT_RED_LED, OUT_RED_LED_PIN, write_output);
  init_output(OUT_GREEN_LED, OUT_GREEN_LED_PIN, write_output);
  init_output(OUT_BARRIER, OUT_BARRIER_PIN, write_output);
  
  //Registering states
  init_state(STANDBY, standby_next_state, standby_output);
  init_state(ERROR_CARD, errorcard_next_state, errorcard_output);
  init_state(VALID_CARD, validcard_next_state, validcard_output);
  init_state(CAR_UNDER_BARRIER, carunderbarrier_next_state, carunderbarrier_output);
  
  init_machine(m);
}

void init_machine(moore_t* m)
{
	if (m)
	{
		m->num_inputs = NUM_OF_INPUTS;
		m->num_outputs = NUM_OF_OUTPUTS;
		m->num_states = NUM_OF_STATES;
		m->states = states;
		m->inputs = inputs;
		m->outputs = outputs;
		m->current_state = &states[STANDBY];
		m->cycle_limit = TIMELIMIT;
	}
}

void init_state(state_id_t id, next_state_fun_t next, get_output_fun_t out)
{
	states[id].id = id;
	assert(next != NULL && out != NULL);
	states[id].next_state = next;
	states[id].update_output = out;
	printf("State %d initialized\n",states[id].id);
}

void init_input(input_id_t id, pin_t pin, read_in read)
{
  inputs[id].value = 0;
  inputs[id].pin = pin;
  inputs[id].id = id;
  inputs[id].read = read;
  printf("Input %d initialized\n",inputs[id].id);
}

void init_output(output_id_t id, pin_t pin, write_out write)
{
  outputs[id].value = 0;
  outputs[id].pin = pin;
  outputs[id].id = id;
  outputs[id].write = write;
  printf("Output %d initialized\n",outputs[id].id);
}

/*STATE FUNCTIONS*/
void* standby_next_state(input_t* inputs, void* m_states, void* par)
{
	assert(inputs != NULL && m_states !=NULL);
	state_t* stvec = (state_t*)m_states;
	
    bool val_b_sens, val_rfid, val_a_sens;
	
    val_b_sens = inputs[IN_BEFORE_SENSOR].value;
	val_rfid = inputs[IN_RFID].value;
    val_a_sens = inputs[IN_AFTER_SENSOR].value;
    
    if(val_b_sens && val_rfid)
		return &stvec[VALID_CARD];
    if(val_b_sens && !val_rfid)
        return &stvec[ERROR_CARD];
    
    return &stvec[STANDBY];
}

void* errorcard_next_state(input_t* inputs, void* m_states, void* par)
{
	assert(inputs != NULL && m_states !=NULL);
	state_t* stvec = (state_t*)m_states;
    
    bool val_b_sens, val_rfid, val_a_sens;
    
    val_b_sens = inputs[IN_BEFORE_SENSOR].value;
    val_rfid = inputs[IN_RFID].value;
    val_a_sens = inputs[IN_AFTER_SENSOR].value;
    
    if(!val_b_sens)
        return &stvec[STANDBY];
    if(val_b_sens && val_rfid)
        return &stvec[VALID_CARD];

    return &stvec[ERROR_CARD];
}

void* validcard_next_state(input_t* inputs, void* m_states, void* par)
{
	assert(inputs != NULL && m_states !=NULL);
	state_t* stvec = (state_t*)m_states;
    
    bool val_b_sens, val_rfid, val_a_sens;
    
    val_b_sens = inputs[IN_BEFORE_SENSOR].value;
    val_rfid = inputs[IN_RFID].value;
    val_a_sens = inputs[IN_AFTER_SENSOR].value;
    
    if(!val_b_sens)
        return &stvec[STANDBY];
    if(val_a_sens)
        return &stvec[CAR_UNDER_BARRIER];
    
    return &stvec[VALID_CARD];
}

void* carunderbarrier_next_state(input_t* inputs, void* m_states, void* par)
{
	assert(inputs != NULL && m_states !=NULL);
	state_t* stvec = (state_t*)m_states;
    
    bool val_b_sens, val_rfid, val_a_sens;
    
    val_b_sens = inputs[IN_BEFORE_SENSOR].value;
    val_rfid = inputs[IN_RFID].value;
    val_a_sens = inputs[IN_AFTER_SENSOR].value;
    
    if(!val_a_sens)
        return &stvec[STANDBY];
    
    return &stvec[CAR_UNDER_BARRIER];
}

/*OUTPUT FUNCTIONS*/
void standby_output(output_t* outputs, void* par)
{
    system("clear");
    printf("State: Standby (or move down barrier)\n");
    outputs[OUT_RED_LED].value = 1;
    outputs[OUT_GREEN_LED].value = 1;
    outputs[OUT_BARRIER].value = 0;
}

void errorcard_output(output_t* outputs, void* par)
{
    system("clear");
    printf("State: Error Card\n");
    outputs[OUT_RED_LED].value = 1;
    outputs[OUT_GREEN_LED].value = 0;
    outputs[OUT_BARRIER].value = 0;
}

void validcard_output(output_t* outputs, void* par)
{
    system("clear");
    printf("State: Valid Card\n");
    outputs[OUT_RED_LED].value = 0;
    outputs[OUT_GREEN_LED].value = 1;
    outputs[OUT_BARRIER].value = 1;
}

void carunderbarrier_output(output_t* outputs, void* par)
{
    system("clear");
    printf("\nCar under barrier\n");
    outputs[OUT_RED_LED].value = 1;
    outputs[OUT_GREEN_LED].value = 1;
    outputs[OUT_BARRIER].value = 1;
}


void read_input(void* inp)
{
	if(inp)
	{
		input_t* in = (input_t*)inp;
        in->value = 0;
  	if((in->id == IN_BEFORE_SENSOR && strchr(stdin_buffer,'a'))
  		|| (in->id == IN_RFID && strchr(stdin_buffer,'s'))
        || (in->id == IN_AFTER_SENSOR && strchr(stdin_buffer,'d')))
  	 	in->value = 1;
		printf("Input %d - %d\n", in->id, in->value);
	}
}

void write_output(void* outp)
{
	if(outp)
	{
		output_t* out = (output_t*)outp;
		printf("Output %d - %d\n", out->id, out->value);
	}
}

void begin_cycle(void* p)
{
	printf("Send inputs >>> "); 
	gets(stdin_buffer);
}