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

//1.USING 2 STACKS
std::vector<int> PostOrderTraversal_twostacks(Node* root){
    std::vector<int> postorder;
    if(root==NULL) return postorder;
    std::stack<Node*> st1;
    std::stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){
            st1.push(root->left);
        }
        if(root->right!=NULL){
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
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

    std::vector<int> vec = PostOrderTraversal_twostacks(rootNode);
    for(auto x : vec){
        std::cout << x << " ";
    }

    return 0;
}