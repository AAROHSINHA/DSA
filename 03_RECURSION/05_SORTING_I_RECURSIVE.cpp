#include <iostream>
#include <vector>
using namespace std;

/*
1. BUBBLE SORT
=> ITERATIVE
=> RECURSIVE
*/
// -> iterative
void BubbleSort(vector<int>& vector){
    bool swapped = false;
    for(int i = 0; i < vector.size() - 1; i+=1){
        swapped = false;
        for(int j = 1; j < vector.size() - i + 1; j+=1){
            // swap
            if(vector[j] < vector[j - 1]){
                swapped = true;
                int temp = vector[j - 1];
                vector[j - 1] = vector[j];
                vector[j] = temp;
            }
        }
        if(!swapped){
            return;
        }
    }
}
// -> recursive
void RBubbleSort(vector<int>& arr, int n){
    if(n == 1){
        return;
    }
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
    RBubbleSort(arr, n - 1);
}


int main(){
    vector<int> vec = {7, 6, 4, 3};
    for(int a : vec){
        cout << a << " ";
    }
    cout << "\n";
    RBubbleSort(vec, vec.size());
    for(int a : vec){
        cout << a << " ";
    }
    cout << "\n";  
    return 0;
}