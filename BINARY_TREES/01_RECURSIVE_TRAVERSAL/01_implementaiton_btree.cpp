#include <iostream>

/*
// using struct
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
*/

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

int main(){
    /*
    CREATING THIS - 
            1
           /\
          2  3
         /\
        4  5
    */
    Node* rootNode = new Node(1);
    Node* secondNode1 = new Node(2);
    Node* secondNode2 = new Node(3);
    Node* thirdNode1 = new Node(4);
    Node* thirdNode2 = new Node(5);
    rootNode->left = secondNode1;
    rootNode->right = secondNode2;
    secondNode1->left = thirdNode1;
    secondNode2->right = thirdNode2;

    return 0;
}