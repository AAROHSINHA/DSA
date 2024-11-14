#include <iostream>
#include <vector>
#include <queue>

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

// LEVEL ORDER TRAVERSAL
std::vector<std::vector<int>> levelOrderTraversal(Node* head){
    std::vector<std::vector<int>> answer;
    if(head == NULL) return answer;
    std::queue<Node*> q;
    q.push(head);
    while(!q.empty()){
        int size = q.size();
        std::vector<int> level;
        for(int i = 0; i < size; i+=1){
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        answer.push_back(level);
    }
    return answer;
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

    std::vector<std::vector<int>> vec = levelOrderTraversal(rootNode);
    for(int i = 0; i < vec.size(); i+=1){
        for(int x : vec[i]){
            std::cout << x << " ";
        }
    }
    return 0;
}