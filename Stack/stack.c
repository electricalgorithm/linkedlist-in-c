#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(Stack_t* stack, int pushed) {
    if (stack->curr_size + sizeof(int) < stack->stack_size) {
        // Creating stack element
        Node_t* temporary = (Node_t*) malloc(sizeof(Node_t));
        temporary->data = pushed;
        temporary->next = NULL;
        temporary->prev = stack->s_pointer;

        // Assign it to end of the linked list
        stack->s_pointer = temporary;
        // Setting stack size
        stack->curr_size += sizeof(int);
    } else {
        printf("\t[ERR] Stack Overflow\n");
    }
}

int pop(Stack_t* stack) {
    // Creating temp to store adress of sp
    Node_t* temporary = stack->s_pointer;
    // Stack pointer to one backword
    stack->s_pointer = stack->s_pointer->prev;
    // Saving before freeing
    int r_data = temporary->data;
    // Freeing the non-used old element
    free(temporary);
    return r_data;
}

void stack_set_size(Stack_t* stack, uint size) {
    stack->stack_size = size;
    stack->curr_size = 0;
}