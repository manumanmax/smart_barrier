#ifndef IO_H
#define IO_H

#include <stdbool.h>

typedef void (*read_in)(void* in);

typedef void (*write_out)(void* out);

typedef unsigned char pin_t;           
typedef unsigned char binary_io_id_t;  

/* Definition of binary io structure */
struct binary_io_s
{
  binary_io_id_t id;  //io identifiers
  pin_t pin;          //io pin value
  bool value;         //input value
  read_in read;
  write_out write;
};

//Binary io tyep
typedef struct binary_io_s binary_io_t;

//Binary input
typedef binary_io_t input_t;
typedef unsigned char input_id_t;

//Binary output
typedef binary_io_t output_t;
typedef unsigned char output_id_t;

#endif