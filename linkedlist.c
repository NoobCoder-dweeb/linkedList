/* Implementation of the linked list functions */

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

// function to display the linked list
void displayList(const Node* head){
    const Node* current = head;

    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// function to insert a node at the end of the linked list
void insertNode(Node** head, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL || *head == NULL){
        *head = newNode;
        return;
    }

    Node* current = *head;
    
    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

// function to delete the first node
void deleteNodeHead(Node** head){

    // check if the node is empty
    if(head == NULL || *head == NULL)
        return;

    Node* temp = *head;

    *head = (*head)->next;

    free(temp);
    temp = NULL;

}

void deleteNodeTail(Node** head);

void deleteNodeAtPosition(Node** head, int position);

