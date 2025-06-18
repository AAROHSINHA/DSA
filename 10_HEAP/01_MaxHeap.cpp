#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
public:
    int arr[100];
    int size;
    MaxHeap(){
        size = 0;
    }
    void display(){
        for(int i = 1; i <= size; i+=1) cout << arr[i] << " ";
        cout << "\n";
    }
    void insert(int value);
    void deleteRoot();
    void decreaseKey(int key, int data);
};


void MaxHeap::insert(int data){
    // increase size 
    size = size + 1;
    if(size >= 100){
        cout << "MaxHeap is full" << "\n";
        return;
    }

    arr[size] = data;
    int index = size;
    while(index > 1){
        int rootIndex = index/2;
        if(arr[rootIndex] < arr[index]){
            swap(arr[rootIndex], arr[index]);
            index = rootIndex;
            continue;
        }
        break;
    }
    cout << "Element " << data << " Inserted succesfully!" << "\n";
}
void MaxHeap::deleteRoot(){
    if(size == 0){
        cout << "No elements in the heap!" << "\n";
        return;
    }

    // Replace root with last element
    arr[1] = arr[size];
    size--;

    // Percolate down the new root to correct position
    int index = 1;
    while(index <= size){
        int largest = index;
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;

        if(leftChild <= size && arr[leftChild] > arr[largest]) largest = leftChild;
        if(rightChild <= size && arr[rightChild] > arr[largest]) largest = rightChild;

        if(largest != index){
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break;
        }
    }

    cout << "Successfully deleted the root!" << "\n";
}

void MaxHeap::decreaseKey(int key, int value){
    // first check if key present
    int index = -1;
    for(int i = 1; i <= size; i+=1){
        if(arr[i] == key){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout << "NO SUCH KEY PRESENT" << "\n";
        return;
    }

    arr[index] = value;
    // get the value to right positionn
    while(index <= size){
        int rightIndex = 2*index;
        int leftIndex = 2*index + 1;
        if(leftIndex <= size && arr[index] < arr[leftIndex]){
            swap(arr[index], arr[leftIndex]);
            index = leftIndex;
        }else if(rightIndex <= size && arr[index] < arr[rightIndex]){
            swap(arr[index], arr[rightIndex]);
            index = rightIndex;
        }else{
            break;
        }

    }
    cout << key << " REPLACE WITH " << value << " SUCCESFULLY!" << "\n";
}


// HEAPIFY A UNSORTED ARRAY
void heapifyUtil(int arr[], int size, int index){
    int largest = index;
    int left = 2*largest;
    int right = 2*largest + 1;
    if(left <= size && arr[largest] < arr[left]) largest = left;
    if(right <= size && arr[largest] < arr[right]) largest = right;
    if(largest!=index){
        swap(arr[index], arr[largest]);
        heapifyUtil(arr, size, largest);
    }
}

void heapify(int arr[], int size){
    for(int i = size/2; i>=1; i-=1){
        heapifyUtil(arr, size, i);
    }
}

int main(){
    vector<int> numbers = {50, 70, 30, 60, 40};
    MaxHeap h = MaxHeap();
    for(int num : numbers) h.insert(num);
    h.display();
    return 0;
}
