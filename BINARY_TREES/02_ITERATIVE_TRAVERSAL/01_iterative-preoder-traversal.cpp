#include <iostream>
#include <vector>
#include <stack>

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

std::vector<int> PreOrderTraversal(Node* head){
    std::vector<int> preorder;
    if(head == NULL) return preorder;

    std::stack<Node*> st;
    st.push(head);
    while(!st.empty()){
        head = st.top();
        st.pop();
        preorder.push_back(head->data);
        if(head->right!=NULL){
            st.push(head->right);
        }
        if(head->left!=NULL){
            st.push(head->left);
        }
    }
    return preorder;
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
    std::vector<int> vec = PreOrderTraversal(rootNode);
    for(int x : vec){
        std::cout << x << " ";
    }
    return 0;
}