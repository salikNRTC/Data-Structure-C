// linklist.h
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Linked list API */
void insert_head(Node **head, int value);
void insert_tail(Node **head, int value);
bool delete_node(Node **head, int value);
void display_list(Node *head);
void free_list(Node **head);

#endif