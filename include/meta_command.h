#pragma once

// Result enums
typedef enum 
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
}MetaCommandResult;

// Prepare enums
typedef enum
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

 // Run meta commands, ex: ".exit"
MetaCommandResult do_meta_command(InputBuffer* input_buffer)
{
    if(strcmp(input_buffer->buffer, ".exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}