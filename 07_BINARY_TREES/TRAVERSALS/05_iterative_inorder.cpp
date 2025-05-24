#include <iostream>
#include <stack>
#include <vector>
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

void IterativeInorderTraversal(Node* root){
    Node* tempPtr = root;
    stack<Node*> st;
    vector<int> inorder;
    while(true){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr = tempPtr->left;
        }else{
            if(st.empty()) break;
            Node* t = st.top();
            inorder.push_back(t->data);
            st.pop();
            tempPtr = t->right;
        }
    }

    // iterate throught inorder
    for(int num : inorder){
        cout << num << " ";
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
    IterativeInorderTraversal(root);
    return 0;
}




