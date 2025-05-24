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

void IterativePreorderTraversal(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* topNode = st.top();
        st.pop();
        cout << topNode->data << " ";
        if(topNode->right!=NULL) st.push(topNode->right);
        if(topNode->left!=NULL) st.push(topNode->left);
    }
    cout << "\n";
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    IterativePreorderTraversal(root);
    return 0;
}




