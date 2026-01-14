#include "queue.h"

void queue_init(Queue *q)
{
    q->front = 0;
    q->rear  = 0;
    q->count = 0;
}

bool queue_is_empty(Queue *q)
{
    return q->count == 0;
}

bool queue_is_full(Queue *q)
{
    return q->count == QUEUE_MAX;
}

bool queue_enqueue(Queue *q, int value)
{
    if (queue_is_full(q))
        return false;

    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % QUEUE_MAX;
    q->count++;

    return true;
}

bool queue_dequeue(Queue *q, int *value)
{
    if (queue_is_empty(q))
        return false;

    *value = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_MAX;
    q->count--;

    return true;
}
