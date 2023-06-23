#include <iostream>
#include <string.h>
#include "input_buffer.h"
#include "meta_command.h"
#include "statement.h"

void print_prompt()
{
    printf("db > ");
}


int main(int argc, char* argv[])
{

    // Create a buffer
    InputBuffer* input_buffer = new_input_buffer();

    while(true)
    {
        print_prompt();
        read_input(input_buffer);

        // This is for meta commands, any commands that are not an SQL statement is called a meta command
        // we will use do_meta_command to handle our meta statmeents;
        if(input_buffer->buffer[0] == '.')
        {
            switch(do_meta_command(input_buffer))
            {
                case(META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command '%s'\n", input_buffer->buffer);
                    continue;
            }
        }

        // If the command is an SQL statement
        Statement statement;

        // we need to prepare the statement
        // Eventually this will understand SQL statments
        switch(prepare_statement(input_buffer, &statement))
        {
            case(PREPARE_SUCCESS):
                break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'. \n", input_buffer->buffer);
                continue;
        }

        // Execute SQL statement
        execute_statement(&statement);
        printf("Executed. \n");
    }
}

