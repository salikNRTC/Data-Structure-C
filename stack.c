#include "stack.h"

void stack_init(Stack *s)
{
    s->top = -1;
}

bool stack_is_empty(Stack *s)
{
    return s->top == -1;
}

bool stack_is_full(Stack *s)
{
    return s->top == STACK_MAX - 1;
}

bool stack_push(Stack *s, int value)
{
    if (stack_is_full(s))
        return false;

    s->data[++s->top] = value;
    return true;
}

bool stack_pop(Stack *s, int *value)
{
    if (stack_is_empty(s))
        return false;

    *value = s->data[s->top--];
    return true;
}

bool stack_peek(Stack *s, int *value)
{
    if (stack_is_empty(s))
        return false;

    *value = s->data[s->top];
    return true;
}
