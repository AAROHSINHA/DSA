#include <stdio.h>

/*
1. Time Complexity is O(N square)
2. Space Complexity - O(1)
3. Requires lesser number of swaps than many other sorting algorithms
*/

/*
WHAT HAPPENS - 
1. In first step we initialize currrentPointer to 0th index
[64 25 12 22 11]
cPtr = 64
Now we find the minimum number and swap them
[11 25 12 22 64]

2. Then we move the cPtr by 1. 
[11 25 12 22 64]
so from position 1 to end, we find the minimum element and replace it
[11 12 25 22 65]

3. In subsequent steps we keep on repeating this method and final answer is - 
[11 12 22 25 65]
*/

void selection_sort(int* arr, int size){
    int minIndex;
    for(int i = 0; i < size - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // swap the minIndex and i
        if(minIndex!=i){
            // swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
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
    int arr[7] = {4, 10, 2, 3, 7, 1, 5};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    selection_sort(arr, size);
    printArray(arr, size);

    
    return 0;
}