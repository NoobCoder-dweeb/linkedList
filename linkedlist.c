/* Implementation of the linked list functions */

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

// function to check if the linked list is empty
int isEmpty(const Node* head){
    int empty = head == NULL ? 1 : 0;

    return empty;
}

// function to display the linked list
void displayList(const Node* head){
    if(isEmpty(head)){
        printf("NULL\n");
        return;
    }
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
        size += 1;
        return;
    }

    Node* current = *head;
    
    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    size += 1;
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

    size -= 1;

}

void deleteNodeTail(Node** head){
    if(isEmpty(*head) || head == NULL){
        return;
    }

    // if there is only one node, then remove it    
    if((*head)->next == NULL){
        free((*head));
        (*head) = NULL;
        size -= 1;
        return;
    }

    Node* temp = *head;

    // stops at the second-to-last pointer
    // deallocates the last pointer to prevent segmentation fault
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    size -= 1;
}

void deleteNodeAtPosition(Node** head, int position){
    if(isEmpty(*head) || head == NULL)
        return;

    if(position > size){
        printf("Linked List is smaller than index\n");
        return;
    }

    Node* current = *head;
    
    while(current != NULL && position - 1 > 0){
        current = current->next;
        
        position -= 1;
    }
    Node* temp = current->next;

    current = temp->next;

    free(temp);
    temp = NULL;

    size -= 1;
}

