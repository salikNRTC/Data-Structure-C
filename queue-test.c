/*
First in First Out
Where Queues Are Used (Real Systems)
🔥 Embedded / RTOS
    Message queues
    ISR → task communication
    Event buffering

🔥 Linux / Drivers
    Network packet queues
    Work queues
    DMA descriptors

🔥 SDR / DSP
    RX sample buffering
    Demod → Decoder pipelines
    Control message passing

🔥 Producer / Consumer
    Producer → Queue → Consumer

🔥🔥Embedded Rule of Thumb🔥🔥
Use queues for data flow, stacks for control flow
*/
#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q;
    int val;
    bool isFull = 0;
    queue_init(&q);

    for(int i=0; i<QUEUE_MAX; i++){
        isFull = queue_enqueue(&q, i);
        if(!isFull)
        {
            printf("Queue is full\n");
            break;
        }
        
    }
    
    while (queue_dequeue(&q, &val)) {
        printf("Dequeued: %d\n", val);
    }

    return 0;
}
