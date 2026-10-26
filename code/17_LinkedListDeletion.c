#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        
        printf("element> %d\n", ptr->data);

        ptr = ptr->next;

    }
}
// DELETION:--
//  Case 1. Deleting the first Node.
struct Node* deleteFirst(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// Case 2. Delete At A given INDEX(MY METHOD)
void indDelete(struct Node* head, int index){
    struct Node* p = head;
    for(int i = 0; i <index-1; ++i){
        p = p->next;
    }
    struct Node* ptr = p->next;
    p->next = ptr->next;
    free(ptr);
}
// Case 2. Delete At A given INDEX(TUTORIAL METHOD)
struct Node * indDelete2(struct Node * head, int index){
    struct Node* p = head;
    struct Node* q = head->next;
    for ( int i = 0;i<index-1;++i){
        p = p->next;
        q= q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3. Deleting The LAst Node
struct Node * lastDelete(struct Node * head){
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
        
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4. Deleting at the given Node
struct Node * nodeDelete(struct Node* head, struct Node* target){
    struct Node* p = head;
    while(p->next!=target){
        p=p->next;
    }
    p->next = target->next;
    free(target);
    return head;
}
// Case 5. Deleting A Node with given VALUE
struct Node* dataDelete(struct Node* head, int data){
    struct Node* p = head;
    struct Node* q = p->next;
    while(q->data != data){
        p=q;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node* dataDelete2(struct Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    // Case 1: The node to be deleted is the head node
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Case 2: Search for the node in the rest of the list
    struct Node* p = head;
    struct Node* q = head->next;

    while (q != NULL && q->data != data) {
        p = q;
        q = q->next;
    }

    // If q is not NULL, we found the node
    if (q != NULL) {
        p->next = q->next;
        free(q);
    }

    return head;
}
int main(){
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

    second->data = 5;
    second->next = third;

    third->data = 7;
    third->next = fourth;
    
    fourth->data = 11;
    fourth->next = NULL;
    
    printf("list before modifying\n");
    linkedListTraversal(head);

    printf("list After modifying\n");
    // head = indDelete2(head, 2);
    // head = lastDelete(head);
    // head = deleteFirst(head);
    // indDelete(head, 2);
    // head = nodeDelete(head, third);
    head = dataDelete2(head, 7);
    linkedListTraversal(head);



    return 0;
}