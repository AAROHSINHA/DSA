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

// inorder - left - root - right
void rInorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    rInorderTraversal(root->left);
    cout << root->data << "\n";
    rInorderTraversal(root->right);
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
    rInorderTraversal(root);
    return 0;
}
