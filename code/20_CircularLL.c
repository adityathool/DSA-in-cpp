#include <stdio.h>
#include <stdlib.h>

// TITLE. Circular LinkedLists, Traversal,Creation,Insertion, Deletion,etc.
struct Node{
    int data;
    struct Node* next;
};
//  TRAVERSAL METHOD
void linkedListtraversal(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("Element> %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!= head);
}

// INSERTION METHODS
// Case 1. insert at beginning
struct Node * InsertAtStart(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next != head){
        p= p->next;

    }
    // p now points to last element
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
    
}
// Case 2. insert at end
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr ->data= data;
    struct Node* p = head->next;
    while(p->next!= head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
// Case 3. insert at given index
struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;
    
    for(int i=0; i<index-1; ++i){
        p=p->next;
    }
    
    // p should be at index-1 node
    ptr->next = p->next;
    p->next = ptr;
    
    return head;

}
int main() {
	struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    
    // declaring data
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;
    
    fourth->data = 1;
    fourth->next = head;

    printf("list before modification\n");
    linkedListtraversal(head);


    printf("list after Modification\n");
    // head = InsertAtStart(head, 2);
    // linkedListtraversal(head);
    // head = insertAtEnd(head, 10);
    insertAtIndex(head, 11, 3);
    linkedListtraversal(head);

	return 0;
}