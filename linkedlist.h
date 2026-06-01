#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function prototypes for the linked list operations
void displayList(const Node* head);
void insertNode(Node** head, int data);
void deleteNodeHead(Node** head);
void deleteNodeTail(Node** head);
void deleteNodeAtPosition(Node** head, int position);

#endif
