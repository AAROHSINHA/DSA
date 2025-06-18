#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
public:
    int arr[100];
    int size;
    MinHeap(){
        size = 0;
    }
    void display(){
        for(int i = 1; i < size; i+=1) cout << arr[i] << " ";
        cout << "\n";
    }
    void insert(int value);
    void deleteRoot();
};


void MinHeap::insert(int data){
    // increase size
    size = size + 1;
    if(size >= 100){
        cout << "MinHeap is full" << "\n";
        return;
    }
    arr[size] = data;
    int index = 1;
    while(index > 1){
        int rootIndex = index/2;
        if(arr[rootIndex] > arr[index]){
            swap(arr[rootIndex], arr[index]);
            index = rootIndex;
            continue;
        }
        break;
    }
    cout << "Element " << data << " Inserted succesfully!" << "\n";
}
void MinHeap::deleteRoot(){
    if(size == 0){
        cout << "NOT ENOUGH ELEMENTS TO DELETE" << "\n";
        return;
    }

    // Replace root with last element
    arr[1] = arr[size];
    size--;

    int index = 1;
    while(index <= size){
        int smallest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if(left <= size && arr[left] < arr[smallest]) smallest = left;
        if(right <= size && arr[right] < arr[smallest]) smallest = right;

        if(smallest != index){
            swap(arr[index], arr[smallest]);
            index = smallest;
        } else {
            break;
        }
    }

    cout << "Root Deleted Successfully\n";
}

int main(){
    vector<int> data = {20, 10, 40, 50, 30, 70, 60};
    MinHeap h = MinHeap();
    for(int num : data) h.insert(num);
    h.display();
    h.deleteRoot();
    h.display();
    return 0;
}
