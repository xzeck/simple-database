#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

// Input buffer structure
typedef struct
{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;

} InputBuffer;


// Creating new input buffer
InputBuffer* new_input_buffer()
{
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

// Read input buffer
void read_input(InputBuffer* input_buffer)
{
    // read line
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    // validate line
    if(bytes_read <= 0)
    {
        printf("Error reading input \n");
        exit(EXIT_FAILURE);
    }

    // assign to input buffer elements
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

// closing input buffer and releasing memory
void close_input_buffer(InputBuffer* input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}
