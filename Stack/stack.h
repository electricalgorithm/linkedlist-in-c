#ifndef STACK_HEADER
#define STACK_HEADER

    /* Datatypes */
    typedef struct stack_node {
        int data;
        struct stack_node* next;
        struct stack_node* prev;
    } Node_t;

    typedef struct stack_head {
        int stack_size;
        int curr_size;
        struct stack_node* s_pointer;
    } Stack_t;

    /* Functions */
    int pop(Stack_t*);
    void push(Stack_t*, int);
    void stack_set_size(Stack_t*, uint);

#endif