#include <iostream>

/*
Binary Tree is a non linear and heirarchial data structure, which is a tree type structure.
It starts from a root nodes which keeps on splitting further to a left or a right node or null.
Each node consists of a data value, a left ptr and a right ptr
*/

// IMPLEMENTATION OF BTREE
class Node{
public:    
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/*
IMPORTANT POINTS- 
1. The maximum nodes at level L of a binary tree is 2^L
2. The total number of maximum nodes in a binary tree of height H is 2^H - 1
*/

int main(){
  
  
    return 0;
}