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
    if(strncmp(input_buffer->buffer, "insert", 6) == 0)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if(strcmp(input_buffer->buffer, "select") == 0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

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