#include <stdio.h>

int indInsert(int arr[], int size, int capacity, int index, int element){
    if(size>= capacity){
        return 0;
    }
    for (int i = size-1;i>=index; i--){
        arr[i+1] = arr[i];

    }
    arr[index] = element;
}
void show(int arr[], int size){
    for(int i  = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
}
int main (){
    int arr[100] = {1,2,3,5,6,3,2,4,6,7};
    int size = 10;
    indInsert(arr, size, 100, 2, 100);
    size += 1;
    show(arr, size);

    
     return 0;
}