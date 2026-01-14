#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>

#define QUEUE_MAX 16

typedef struct {
    int data[QUEUE_MAX];
    int front;
    int rear;
    int count;
} Queue;

/* Queue API */
void queue_init(Queue *q);
bool queue_enqueue(Queue *q, int value);
bool queue_dequeue(Queue *q, int *value);
bool queue_is_empty(Queue *q);
bool queue_is_full(Queue *q);

#endif
