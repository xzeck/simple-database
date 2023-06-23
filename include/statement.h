#pragma once
#include "input_buffer.h"
#include "meta_command.h"

typedef enum
{
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct 
{
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement *statement)
{
    // check if the first 6 of characters of input are insert
    if(strncmp(input_buffer->buffer, "insert", 6) == 0)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    // check if input is select
    if(strcmp(input_buffer->buffer, "select") == 0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

// execute the statement
void execute_statement(Statement* statement)
{
    switch(statement->type)
    {
        case (STATEMENT_INSERT):
            printf("insert\n");
        break;

        case (STATEMENT_SELECT):
            printf("select\n");
        break;
    }
}