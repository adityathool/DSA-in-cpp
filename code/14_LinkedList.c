#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void linkedListtraversal(struct Node* ptr){
    while(ptr != NULL){
    printf("element: %d ", ptr->data);
    ptr = ptr->next;
    }
}
int main (){
    // heap allocated Node blocks
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));

    struct Node* third = (struct Node*)malloc(sizeof(struct Node)); 
    // linking fiest and second nodes
    head->data = 7;
    head-> next = second;
    
    // linknig second and third nodes
    second->data = 8;
    second->next = third;

    // terminating the list at third node
    third->data = 11;
    third->next = NULL;
    linkedListtraversal(head);



    return 0;
}