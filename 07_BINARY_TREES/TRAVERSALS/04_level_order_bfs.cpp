#include <iostream>
#include <queue>
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

/*
1. ek queue me root ko daalo
2. ab queue ke top ko nikalo, print karo, uske left ko queue me dalo,  right ko queue me dalo
3. fir queue ke top ko nikalo and step 2 repeat
*/
void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* top = q.front();
        q.pop();
        cout << top->data << " ";
        if(top->left!=NULL) q.push(top->left);
        if(top->right!=NULL) q.push(top->right);
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
    LevelOrderTraversal(root);
    return 0;
}




