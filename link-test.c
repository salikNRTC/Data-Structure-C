/*
Why use Linked Lists when you have arrays?
Let’s compare arrays and linked lists:

Feature	                       Array	                                  Linked List
Memory allocation	        Fixed (static or malloc)	                Dynamic (nodes allocated on demand)
Insertion / Deletion	    Slow (O(n), need to shift elements)	        Fast (O(1) if you have pointer)
Access	                    Fast random access (O(1))	                Slow (O(n) sequential access)
Size flexibility 	        Static size, must reallocate	            Can grow/shrink dynamically
✅ Key insight

Use arrays when you know size and need fast random access.
Use linked lists when you need dynamic size and frequent insert/delete.

Example Scenario:
    Array: I want to store a list of SDR channels: fixed size 50 → array is perfect.
    Linked list: I want to maintain an ordered list of active radio sessions. 
    New sessions can start or end at any time → linked list is perfect.

Analogy you will never forget
    Think of array vs linked list as train vs metro stations:

    Array: All train cars connected in a line, rigid. Want to insert/remove a car in the middle 
    → you have to detach and shift all cars.

    Linked list: Each station is a node, connected by pointers. Adding/removing a station 
    → just rewire pointers.

    Double linked list: Stations know their previous and next station 
    → you can go forward or backward without starting from the beginning.
*/

// link-test.c
#include <stdio.h>
#include "linklist.h"

int main() {
    Node *head = NULL;

    // Insert elements at head
    insert_head(&head, 10);
    insert_head(&head, 20);

    // Insert elements at tail
    insert_tail(&head, 5);
    insert_tail(&head, 30);

    printf("List after insertions:\n");
    display_list(head);

    // Delete a node
    if(delete_node(&head, 20)) {
        printf("Deleted 20\n");
    } else {
        printf("20 not found\n");
    }

    printf("List after deletion:\n");
    display_list(head);

    // Free entire list
    free_list(&head);

    return 0;
}
