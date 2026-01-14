/*
1️⃣ Why pointers are needed at all
In C:
Function arguments are passed by value
That means a function receives copies, not originals

If you want a function to:
    Modify a structure
    Return more than one value
    Change data in the caller
👉 You must pass addresses (pointers).
*/

/* 
Stacks --> Last in First Out
“Finish the most recent task first”

2️⃣ WHERE stacks are used (MOST IMPORTANT)
🔥 1. CPU Call Stack (MOST CRITICAL)
Every program uses a stack even if you don’t write one.
What the call stack stores:
    Function return address
    Local variables
    Function arguments
    Saved registers

🔥 2. Embedded Systems / RTOS
Used for:
    Task stacks (each thread has its own stack)
    Interrupt Service Routines (ISR stack)
    Context switching

🔥 3. Expression Evaluation (Compilers, DSP)
Stacks are used for:
    Parsing expressions
    Evaluating infix/postfix
    Syntax checking

🔥 4. Recursion
Each recursive call pushes:
    Local variables
    Return address    

🔥 5. Undo / Redo (Applications)
Used in:
    Text editors
    CAD tools
    Image processing software
    
🔥 6. Networking & Protocol Stacks (Your Domain)
Stacks are used for:
    Packet processing pipelines
    Nested protocol decoding

🔥 7. DSP & SDR Signal Processing
In SDR waveform processing:
    Buffer management
    Nested state machines
    Call chains in DSP pipelines

🔥 8. Linux Kernel
Stacks are used everywhere:
    Per-process kernel stack
    Per-CPU stack
    Interrupt stack
📌 Linux kernel stack is small (8–16 KB) → overflow = panic

***Stacks exist because programs naturally execute in reverse order of execution requests.***
    */
#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack s;
    int value;

    stack_init(&s);

    stack_push(&s, 10);
    stack_push(&s, 20);
    stack_push(&s, 30);

    int current = 0;
    stack_peek(&s, &current);
    printf("Element at Top: %d \n", current);

    while (stack_pop(&s, &value)) {
        printf("Popped: %d\n", value);
    }

    return 0;
}
