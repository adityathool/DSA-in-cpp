#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr; // will be requesting array in heap instead of stack
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct  stack* s, int value){
    if(isFull(s)){
        printf("StackOverflow!!!\n");
    }
    else{
        s->top++;
        s->arr[s->top] = value;
    }
}
int pop(struct stack* s){
    if(isEmpty(s)){
        printf("StackEmpty!!");
        return -1;
    }
    else{
        int val = s->arr[s->top]; 
        s->top--; 
        return val;
    }
}

void peep(struct stack * ptr){
    for(int i = 0; i<ptr->top+1; ++i){
        printf("element> %d\n", ptr->arr[i]);
    }
}
int main() {
    struct stack *s;
    s->size = 8;
    s->top = -1; // stack is currently empty
    s->arr = (int *)malloc(s->size * sizeof(int));
	push(s, 10);
    push(s, 2);
    push(s, 3);
    push(s, 150);
    int val = pop(s);
    peep(s);
    printf("popped out> %d\n", val);
	return 0;
}