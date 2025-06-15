#include <iostream>
using namespace std;

// making the Node
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

/*
void morrisInorder(Node* root) {
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            // Find the inorder predecessor
            Node* pred = current->left;
            while (pred->right != nullptr && pred->right != current) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                // Make thread
                pred->right = current;
                current = current->left;
            } else {
                // Thread exists, remove it
                pred->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}
*/
void morrisInorder(Node* root){
    Node* currPtr = root;
    while(currPtr!=NULL){
        if(currPtr->left==NULL){
            cout << currPtr->data << " ";
            currPtr = currPtr->right;
        }else{
            // find the inorder predecessor
            Node* predPtr = currPtr->left;
            while(predPtr->right!=NULL && predPtr->right!=currPtr){
                predPtr = predPtr->right;
            }

            // if no thread exists make one
            if(predPtr->right==NULL){
                predPtr->right = currPtr;
                currPtr = currPtr->left;
            }else{
                // means a thread exists, break it
                predPtr->right = NULL;
                cout << currPtr->data << " ";
                currPtr = currPtr->right;
            }

        }
    }
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
    morrisInorder(root);
    return 0;
}
