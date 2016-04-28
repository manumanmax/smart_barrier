#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include "state.h"
#include "io.h"
#include "mooremachine.h"

//Private functions
long long get_time();
static void update_state(moore_t* m);
static void read_inputs(moore_t* m);
static void write_outputs(moore_t* m);

//Main Cycle
void run(moore_t* m, cycle_fun begin_run, void* p)
{
  long long time = 0;
  long long time_diff = 0;
  
  while(true) {
  	time = get_time();
    //begin_run(p);
    read_inputs(m);
    update_state(m);
    write_outputs(m);
    if (labs(get_time() - time)*1000 > m->cycle_limit)
    	printf("Exceeded cycle time limit!\n");	 
  }
}

void update_state(moore_t* m)
{
	m->current_state = (state_t*)m->current_state->next_state(m->inputs, (void*)m->states, NULL);
	printf("New State %d\n", m->current_state->id);
}

void write_outputs(moore_t* m)
{
	int i;
	m->current_state->update_output(m->outputs,NULL);
	for(i = 0; i < m->num_outputs; i++)
		m->outputs[i].write(&(m->outputs[i]));
}

void read_inputs(moore_t* m)
{
  int i;
  for(i = 0; i < m->num_inputs; i++)
		m->inputs[i].read(&(m->inputs[i]));
}

long long get_time() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // caculate milliseconds
    return milliseconds;
}