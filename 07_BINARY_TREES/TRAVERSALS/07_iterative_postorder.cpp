#include <iostream>
#include <stack>
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

void IterativePostOrderTraversal(Node* head){
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(head);
    while(!st1.empty()){
        Node* curr = st1.top();
        st1.pop();
        if(curr->left!=NULL) st1.push(curr->left);
        if(curr->right!=NULL) st1.push(curr->right);
        st2.push(curr);
    }

    // now printing the elements
    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
    cout << "\n";

}

int main(){
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->right = new Node(6);
    IterativePostOrderTraversal(head);
    return 0;
}