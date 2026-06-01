
#include "linkedlist.h"

int main() {
    Node* head = NULL;
    
    insertNode(&head, 10);
    insertNode(&head, 20);

    displayList(head);
    
    deleteNodeHead(&head);
    
    displayList(head);
    
    deleteNodeTail(&head);

    displayList(head);
    
    return 0;
}