#include <stdio.h>
#include <stdlib.h>

// Tutotial 21. DOubly linked lists implementation and uses scenarios
//Defination: a list of data in which, each element keeps track of its all neighbouring elements(nodes).

//pros. 
// 1. Bidirectional Traversal: a node keeps track of its previous as well as next node, so if a node pointer is given, 
//    its neighbouring nodes can be accessed.
// 2. No need of extra iterating pointer: like in single linked list , we had 2 pointers to use to insert or delete.

//cons.
// 1. Better accessibility at te cost of memory: each node has an extra 8 bytes of pointer which will consume large memory as data grows.

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void doubleListTraversal(struct Node* head, const char* f_r){
    
    if(f_r=="forward"){
        struct Node* ptr = head;
        while(ptr!=NULL){
            printf("Element> %d\n", ptr->data);
            ptr=ptr->next;
            
        }
      
    }
    else if(f_r=="backward"){
        struct Node* ptr = head;
        struct Node* p = head;
        while(p->next!=NULL){
            p = p->next;   
        }
        ptr = p;
        while(ptr!= NULL){
            
            printf("Element> %d\n", ptr->data);
            ptr = ptr->prev;
        }
       
    
    }
    
    
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    head->prev = NULL;
    head->next = second;
    head->data = 10;

    second->prev = head;
    second->next = third;
    second->data = 4;

    third->prev = second;
    third->next = fourth;
    third->data = 3;


    fourth->prev = third;
    fourth->next = NULL;
    fourth->data = 6;

    doubleListTraversal(head, "backward");
    
	free(head);
    free(second);
    free(third);
    free(fourth);


	return 0;
}