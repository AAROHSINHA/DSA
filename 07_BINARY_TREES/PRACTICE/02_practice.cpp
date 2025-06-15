#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
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


// 1. CHECK IF Node S is a Subtree of Node T
// approach - do inorder traversal and compare
vector<int> inorderTraversal(Node* root){
    vector<int> inorder;
    Node* currPtr = root;
    while(currPtr!=NULL){
        if(currPtr->left==NULL){
            inorder.push_back(currPtr->data);
            currPtr = currPtr->right;
        }else{
            Node* predPtr = currPtr->left;
            while(predPtr->right!=NULL && predPtr->right!=currPtr){
                predPtr = predPtr->right;
            }

            if(predPtr->right == NULL){
                predPtr->right = currPtr;
                currPtr = currPtr->left;
            }else{
                predPtr->right = NULL;
                inorder.push_back(currPtr->data);
                currPtr = currPtr->right;
            }
        }
    }
    return inorder;
}

bool isSubTree(Node* T, Node* S) {
    vector<int> vec1 = inorderTraversal(T);
    vector<int> vec2 = inorderTraversal(S);
    int ptr1 = -1;
    int ptr2 = 0;
    for(int i = 0; i < vec1.size(); i+=1){
        if(vec1[i] == vec2[0]){
            ptr1 = i;
            break;
        }
    }
    if(ptr1 == -1) return false;
    while(ptr1 < vec1.size() && ptr2 < vec2.size()){
        if(vec1[ptr1++]!=vec2[ptr2++]) return false;
    }
    return ptr2 == vec2.size();
}

// Unique number of binary trees from 1-n
// this is catalan recurrance.
int uniqueBtrees(int n){
    vector<int> factorial = {1};
    int fact = 1;
    for(int i = 1; i <= 2*n; i+=1){
        factorial.push_back(factorial.back()*i);
    }

    int unique = 0;
    for(int i = 1; i <= n; i+=1){
        int term1 = i - 1;
        int term2 = n - i;
        int c1 = factorial[2*term1] / (factorial[term1]*factorial[term1+1]);
        int c2 = factorial[2*term2] / (factorial[term2]*factorial[term2+1]);
        unique += c1*c2;
    }
    return unique;
}

// 2. VERTICAL TRAVERSAL
vector<vector<int>> verticalOrder(Node *root) {
    vector<pair<Node*, int>> levels;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int currHeight = q.size();
        for(int i = 0; i < currHeight; i+=1){
            Node* currNode = q.front().first;
            int index = q.front().second;
            levels.push_back({currNode, index});
            q.pop();
            if(currNode->left!=NULL) q.push({currNode->left, index-1});
            if(currNode->right!=NULL) q.push({currNode->right, index+1});   
        }
    }
    sort(levels.begin(), levels.end(), [](const pair<Node*, int>& a, const pair<Node*, int>& b){
        return a.second < b.second;
    });
    vector<vector<int>> res;
    vector<int> vec = {levels[0].first->data};
    for(int i = 1; i < levels.size(); i+=1){
        if(levels[i].second == levels[i - 1].second){
            vec.push_back(levels[i].first->data);
        }else{
            res.push_back(vec);
            vec = {};
            vec.push_back(levels[i].first->data);
        }
    }
    res.push_back(vec);
    // for(pair<Node*, int> level : levels){
    //     cout << level.first->data << " - " << level.second << "\n";
    // }
    return res;
}

// 3. EXTREME NODES IN ALTERNATE ORDER
    vector<int> extremeNodes(Node* root) {
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    int sign = -1;
    while(!q.empty()){
        int height = q.size();
        for(int i = 0; i < height; i+=1){
            Node* currPtr = q.front();
            q.pop();
            if(sign == 1 && i == 0) ans.push_back(currPtr->data);
            else if(sign == -1 && i == height - 1) ans.push_back(currPtr->data);
            if(currPtr->left!=NULL) q.push(currPtr->left);
            if(currPtr->right!=NULL) q.push(currPtr->right);
        }
        sign*=-1;

    } 
    return ans;
}

// pair in binary tree with given sum
bool findTarget(Node *root, int target) {
    vector<int> inorder;
    Node* currPtr = root;
    while(currPtr!=NULL){
        if(currPtr->left == NULL){
            inorder.push_back(currPtr->data);
            currPtr = currPtr->right;
        }else{
            Node* predPtr = currPtr->left;
            while(predPtr->right!=NULL && predPtr->right!=currPtr){
                predPtr = predPtr->right;
            }

            if(predPtr->right==NULL){
                predPtr->right = currPtr;
                currPtr = currPtr->left;
            }else{
                predPtr->right = NULL;
                inorder.push_back(currPtr->data);
                currPtr = currPtr->right;
            }
        }
    }

    // now simple 2 pointer on inorder
    int low = 0;
    int high = inorder.size() - 1;
    while(high > low){
        int sum = inorder[low] + inorder[high];
        if(sum == target){
            return true;
        }else if(sum > target){
            high-=1;
        }else{
            low+=1;
        }
    }
    return false;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<int> res = extremeNodes(root);
    for(int num : res){
        cout << num << "\n";
    }

    return 0;
}