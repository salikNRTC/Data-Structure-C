#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdbool.h>

#define STACK_MAX 100

typedef struct {
    int data[STACK_MAX];
    int top;
} Stack;

/* Stack API */
void stack_init(Stack *s);
bool stack_push(Stack *s, int value);
bool stack_pop(Stack *s, int *value);
bool stack_peek(Stack *s, int *value);
bool stack_is_empty(Stack *s);
bool stack_is_full(Stack *s);

#endif
