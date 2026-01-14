// linklist.c
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

void insert_head(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insert_tail(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

bool delete_node(Node **head, int value) {
    if (*head == NULL) return false;

    Node *temp = *head;
    Node *prev = NULL;

    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        return true;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    }

    prev->next = temp->next;
    free(temp);
    return true;
}

void display_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
