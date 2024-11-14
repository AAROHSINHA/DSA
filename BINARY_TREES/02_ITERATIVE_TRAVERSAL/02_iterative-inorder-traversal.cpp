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

std::vector<int> InOrderTraversal(Node* root){
    std::stack<Node*> st;
    Node* node = root;
    std::vector<int> inorder;
    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
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

    std::vector<int> vec = InOrderTraversal(rootNode);
    for(int x : vec){
        std::cout << x << " ";
    }
    return 0;
}