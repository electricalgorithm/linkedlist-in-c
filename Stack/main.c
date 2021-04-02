#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack_t* _stack = (Stack_t*) malloc(sizeof(Stack_t));
    stack_set_size(_stack, 2*sizeof(int)); // Setting stack_size = 8192 bytes

    push(_stack, 100);
    printf("Last Element: %d\n", _stack->s_pointer->data);
    
    push(_stack, 12);
    printf("Last Element: %d\n", _stack->s_pointer->data);
    
    push(_stack, 25987132);
    printf("Last Element: %d\n", _stack->s_pointer->data);
    
    pop(_stack);
    printf("Last Element: %d\n", _stack->s_pointer->data);

    pop(_stack);
    printf("Last Element: %d\n", _stack->s_pointer->data);

    return 0;
}