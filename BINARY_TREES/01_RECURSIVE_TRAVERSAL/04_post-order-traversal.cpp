#include <iostream>

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

// POST ORDER TRAVERSAL
void PostOrderTraversal(Node* head){
    if(head == NULL){
        return;
    }

    PostOrderTraversal(head->left);
    PostOrderTraversal(head->right);
    std::cout << head->data << " ";
}

int main(){
    Node* rootNode = new Node(1);
    rootNode->left = new Node(2);
    rootNode->right = new Node(3);
    rootNode->left->left = new Node(4);
    rootNode->left->right = new Node(5);
    rootNode->left->right->left = new Node(6);

    rootNode->right = new Node(3);
    rootNode->right->left = new Node(7); 
    rootNode->right->right = new Node(8);
    rootNode->right->right->left = new Node(9);
    rootNode->right->right->right = new Node(10);
    PostOrderTraversal(rootNode);
    return 0;
}