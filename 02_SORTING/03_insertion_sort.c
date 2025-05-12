#include <stdio.h>
#include <stdbool.h>

/*
1. Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. The unsorted one is basically the array left to our currentPointer.
*/

void insertion_sort(int* arr, int size){
    for(int i = 1; i < size; i++){
        int swapping_index = i;
        while(swapping_index > 0 && arr[swapping_index] < arr[swapping_index - 1]){
            // swap and make swapped true
            int temp = arr[swapping_index];
            arr[swapping_index] = arr[swapping_index - 1];
            arr[swapping_index - 1] = temp;
            swapping_index-=1;
        }
    }
}

void printArray(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main(){
    int arr[5] = {5, 3, 4, 1, 2};
    int size = sizeof(arr)/sizeof(int);
    printArray(arr, size);
    insertion_sort(arr, size);
    printArray(arr, size);

    return 0;
}

