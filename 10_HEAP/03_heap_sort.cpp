#include <iostream>
#include <vector>
using namespace std;

/*
FOR 0-indexed array - 
root - i
left = 2i + 1
right = 2i + 2
parent = (i - 1)/2
*/

void heapifyUtil(vector<int> &nums, int index){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < nums.size() && nums[left] > nums[largest]) largest = left;
    if(right < nums.size() && nums[right] > nums[largest]) largest = right;

    if(largest != index){
        swap(nums[index], nums[largest]);
        heapifyUtil(nums, largest);
    }
}

void heapify(vector<int> &nums){
    for(int i = nums.size()/2 - 1; i >= 0; i--){
        heapifyUtil(nums, i);
    }
}


void heapSort(vector<int> &vec){
    heapify(vec); // now we have a max Heap
    vector<int> nums(vec.size(), -1);
    int sortedIndex = vec.size() - 1;
    while(!vec.empty()){
        nums[sortedIndex--] = vec.front();
        vec[0] = vec[vec.size() - 1];
        vec.pop_back();
        heapify(vec);
    }
    vec = nums;
}

int main(){
    return 0;
}