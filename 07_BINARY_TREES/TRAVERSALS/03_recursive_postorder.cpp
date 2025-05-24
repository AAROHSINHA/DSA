#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// post - left - right - left
void rPostOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    rPostOrderTraversal(root->left);
    rPostOrderTraversal(root->right);
     cout << root->data << "\n";
}

int main(){
    // making a tree - perfect binary tree of max level - 2 - {0, 1, 2}
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    rPostOrderTraversal(root);
    return 0;
}
