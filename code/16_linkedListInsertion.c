#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void linkedListtraversal(struct Node* ptr){
    while(ptr != NULL){
    printf("element: %d \n", ptr->data);
    ptr = ptr->next;
    }
}
struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr =  (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;

}
void insertInBetween( struct Node* head, int index, int data){
    struct Node* p = head;
    for(int i = 0; i < index-1; ++i){
        p = p->next;
    }

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}
void insertAtEnd(struct Node* head, int data ){
    struct Node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL; 

}
void insertAtNode(struct Node* q, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = q->next;
    
    q->next= ptr;
    ptr->data = data;


}

int main (){
    // heap allocated Node blocks
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));

    struct Node* third = (struct Node*)malloc(sizeof(struct Node)); 
    // linking first and second nodes
    head->data = 7;
    head-> next = second;
    
    // linking second and third nodes
    second->data = 8;
    second->next = third;

    // terminating the list at third node
    third->data = 11;
    third->next = NULL;
    linkedListtraversal(head);
    head = insertAtFirst(head, 5666);
    printf("\n");
    linkedListtraversal(head);
    insertInBetween(head, 3, 4);
    printf("\n");
    linkedListtraversal(head);
    insertAtEnd(head, 495405);
    printf("\n");
    linkedListtraversal(head);
    insertAtNode(third, 20);
    printf("\n");
    linkedListtraversal(head);






    return 0;
}  