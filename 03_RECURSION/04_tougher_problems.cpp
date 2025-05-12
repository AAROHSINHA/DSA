#include <iostream>
#include <vector>
using namespace std;

// 1. REVERSE A LINKED LIST USING ITERATION AND RECURSION
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

// iterative -
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    cout << "\n";
}

// recursive - 
void RTraverseLinkedList(Node* head){
    if(head == NULL){
        cout << "\n";
        return;
    }
    cout << head->data << " ";
    RTraverseLinkedList(head->next);
}
void RReverseTraversal(Node* head){
    if(head == NULL){
        return;
    }
    RReverseTraversal(head->next);
    cout << head->data << " ";
}
//
//
//
//
//
// 2. BINARY SEARCH
// --> iterative
int IBinarySearch(vector<int> vector, int target){
    int low = 0;
    int high = vector.size() - 1;
    int mid;
    while(high >= low){
        mid = low + (high - low)/2;
        if(vector[mid] == target){
            return mid;
        }else if(vector[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}
// --> recursive
int RBinarySearch(vector<int> vector, int target, int low, int high){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low)/2;
    if(vector[mid] == target){
        return mid;
    }else if(vector[mid] < target){
        return RBinarySearch(vector, target, mid + 1, high);
    }else{
        return RBinarySearch(vector, target, low, mid - 1);
    }
}

// 3. CHECK IF ARRAY IS SORTED
// ---> iterative
bool ICheckSorted(vector<int> vec){
    for(int i = 1; i < vec.size(); i+=1){
        if(vec[i] < vec[i - 1]){
            return false;
        }
    }
    return true;
}
// ---> recursive
bool RCheckSorted(vector<int> vec, int index){
    // base case
    if(index == 0){
        return true;
    }
    // comparision
    if(vec[index] < vec[index - 1]){
        return false;
    }
    return RCheckSorted(vec, index - 1);
}
// --> another recursive method - popping elements
bool RCheckSorted2(vector<int> vec){
    if(vec.size() <= 1){
        return true;
    }
    if(vec[vec.size() - 1] < vec[vec.size() - 2]){
        return false;
    }
    vec.pop_back();
    return RCheckSorted2(vec);
}
/*
As the second one contains n vectors of size n, n-1, n-2 in successive recursive calls...
It is basically in space complexity O(nsquare) which is significantlly lesser than 
the first one.
*/
//
//
//
//
//
// 4. CHECK IF A NUMBER IS PALINDROME OR NOT
// --> recursive
int getReverse(int number, int reversed = 0) {
    if (number == 0) {
        return reversed;
    }
    int digit = number % 10;
    return getReverse(number / 10, reversed * 10 + digit);
}
//
//
//
//
//
// 5. Iterative implementation of atoi - convert string representing number to integer
int Ratoi(string number){
    if(number == ""){
        return 0;
    }
    int n = number.back() - '0';
    number.pop_back();
    return Ratoi(number) * 10 + n; 
}

int main(){
    cout << Ratoi("12345") << "\n";
    return 0;
}