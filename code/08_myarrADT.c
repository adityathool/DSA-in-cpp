# include <stdio.h>
#include <stdlib.h>
struct myArr{

    int total_size;
    int used_size;
    int* ptr;
};
void createArr(struct myArr* a, int tsize, int usize){
    a->total_size =  tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize*sizeof(int));
}
void show(struct myArr* a){
    for (int i = 0; i<a->used_size; i++){
        printf("%d\n", a->ptr[i]);
    }
}
void setArr(struct myArr* a){
    int n;
    for (int i = 0; i<a->used_size; ++i){
        printf("enter element %d\n", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
}
}
int main(){
    struct myArr marks;
    createArr(&marks, 10, 4);
    printf("calling set\n");
    setArr(&marks);
    printf("calling show\n");
    
    show(&marks);

    return 0;
}