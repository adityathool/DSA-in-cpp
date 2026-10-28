#include <stdio.h>
#include <stdlib.h>
// STACKS:

//    TOP POINTER
//        │
//        ▼
//  ┌───────────┐
//  │    40     │ <─── Top Element (Last In, First Out)
//  ├───────────┤
//  │    30     │
//  ├───────────┤
//  │    20     │
//  ├───────────┤
//  │    10     │ <─── Bottom Element (First In)
//  └───────────┘

//[ 50 ]  ──►  [ Push ]  ──►         │    50     │ <─── NEW TOP
//                                   ├───────────┤
//                                   │    40     │
//                                   │    ...    │

// │    40     │ <─── TOP    ──►  [ Pop ]  ──►  Returns: 40
// ├───────────┤                               New TOP is: 30
// │    30     │ <─── NEW TOP

// ===================================================================
//                      THE LIFO PRINCIPLE (STACK)
// ===================================================================

//   [ INSERTION ]                             [ DELETION / RETRIEVAL ]
//   📥 PUSH (Last In)                         📤 POP (First Out)
//         │                                         ▲
//         ▼                                         │
//  ┌─────────────┐                           ┌─────────────┐
//  │  Element D  │ ◄───────  [ TOP ]  ──────►│  Element D  │
//  ├─────────────┤                           └─────────────┘
//  │  Element C  │                                  │
//  ├─────────────┤                           ┌─────────────┐
//  │  Element B  │                           │  Element C  │
//  ├─────────────┤                           ├─────────────┤
//  │  Element A  │ ◄─────── [ BOTTOM ] ─────►│     ...     │
//  └─────────────┘                           └─────────────┘

// the element that goes in first, if taken out last or
// the element that goes in last, is taken out first.

// stack implementation using arrays

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
void push(struct stack * ptr, int data){
    ptr->arr[ptr->top+1] = data;
    ptr->top++;
}
void peep(struct stack * ptr){
    for(int i = 0; i<ptr->top+1; ++i){
        printf("element> %d\n", ptr->arr[i]);
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;// stack is currently empty
    // s.arr = (int*)malloc(s.size*sizeof(int));

    struct stack *s;
    s->size = 80;
    s->top = -1; // stack is currently empty
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 10);
    push(s, 13);
    push(s, 140);
    push(s, 4);
    peep(s);
    printf("%d", isEmpty(s));
    return 0;
}