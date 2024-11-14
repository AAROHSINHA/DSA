#include <iostream>
#include <vector>
#include <stack>
#include <queue>

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;        
    }
};

// print Spiral -> using 2 stacks
std::vector<int> findSpiral(Node *root){
    std::vector<int> answer;
    if(root == NULL) return answer;
    std::stack<Node*> st1;
    std::stack<Node*> st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            Node* temp = st1.top();
            st1.pop();
            answer.push_back(temp->data);
            if(temp->right!=NULL) st2.push(temp->right);
            if(temp->left!=NULL) st2.push(temp->left);
        }
        while(!st2.empty()){
            Node* temp = st2.top();
            st2.pop();
            answer.push_back(temp->data);
            if(temp->left!=NULL) st1.push(temp->left);
            if(temp->right!=NULL) st1.push(temp->right);
        }
    }
    return answer;
}


int main(){
    Node* rootNode = new Node(1);
    rootNode->left = new Node(2);
    rootNode->right = new Node(3);
    rootNode->left->left = new Node(4);
    rootNode->left->right = new Node(5);
    rootNode->right->left = new Node(6);
    rootNode->right->right = new Node(7);
    std::cout << "x";
    std::vector<int> v = findSpiral(rootNode);
    std::cout << v.size();
    return 0;
}