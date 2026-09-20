#include <stdio.h>
void indDelete(int arr[], int size, int index){
    for (int i = index; i<size-1;++i){
        arr[i] = arr[i+1];

    }
}
void show(int arr[], int size){
    for(int i  = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int arr[100] = {7,8,6,4,3,2,4,5};
    int size = 8;
    show(arr, size);
    indDelete(arr, 8, 2);
    size-=1;
    show(arr, size);


    return 0;
}