#include <stdio.h>
#include <stdbool.h>

/*
1. Bubble sort is a sorting algorithm which sorts the array using alternate swappings.
2. Its time complexity is o(n square), means quite high
3. Space complexity - O(1)
*/
void bubble_sort(int* arr, int size){
    // start sorting
    bool swapped = false;
    for(int i = 0; i < size - 1; i++){
        swapped = false;
        for(int j = 0; j < size - i - 1; j++){
            // swapping logic
            if(arr[j] > arr[j + 1]){
                // swap and make swapped = true
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        // if swapped is true continue
        // if swapped is false, means no swapping happen, means the array is sorted so break
        if(!swapped){
            break;
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
    int arr[5] = {2, 4, 1, 0, 7};
    printArray(arr, 5);
    bubble_sort(arr, 5);
    printArray(arr, 5);


    return 0;
}
