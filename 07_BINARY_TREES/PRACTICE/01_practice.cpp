#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
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

// helper - level order bfs
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


// 1. Iterative Inorder
void IterativeInorderTraversal(Node* head){
    Node* tempPtr = head;
    stack<Node*> st;
    while(true){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr = tempPtr->left;
        }else{
            Node* topPtr = st.top();
            st.pop();
            cout << topPtr->data << " ";
            tempPtr = topPtr->right;
        }
    }
    cout << "\n";
}

// 2. Height of Binary Tree
/*
Algorithm  - 
We will use 2 queues for this.
We will apply the logic of iterative level traversal
*/
int height(Node* root) {
    queue<Node*> q1;
    queue<Node*> q2;
    vector<vector<Node*>> levels;
    q1.push(root);
    while(!q1.empty()){
        vector<Node*> level;
        while(!q1.empty()){
            Node* currTop = q1.front();
            level.push_back(currTop);
            if(currTop->left!=NULL) q2.push(currTop->left);
            if(currTop->right!=NULL) q2.push(currTop->right);
            q1.pop();
        }
        levels.push_back(level);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    return levels.size() - 1;
    // note that height is ain height - 1 as root is level 0
}

// Optimal height code
int height2(Node* root){
    queue<Node*> q;
    int depth = 0;
    q.push(root);
    while(!q.empty()){
        int currHeight = q.size();
        for(int i = 0; i < currHeight; i++){
            Node* currNode = q.front();
            q.pop();
            if(currNode->left!=NULL) q.push(currNode->left);
            if(currNode->right!=NULL) q.push(currNode->right);
        }
        depth++;
    }
    return depth - 1;
}

// 3. CHECK FOR IDENTICAL TREES 
// APPLY ITERATIVE POSTORDER PARALLELY
bool isIdentical(Node *r1, Node *r2) {
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(r1);
    st2.push(r2);
    while(!st1.empty() && !st2.empty()){
        Node* topNode1 = st1.top();
        Node* topNode2 = st2.top();
        st1.pop();
        st2.pop();
        if(topNode1->data!=topNode2->data){
            return false;
            cout << "false1";
        };
        if(topNode1->right!=NULL && topNode2->right!=NULL){
            if(topNode1->right->data != topNode2->right->data) return false;
            st1.push(topNode1->right);
            st2.push(topNode2->right);
        }
        if(topNode1->left!=NULL && topNode2->left!=NULL){
            if(topNode1->left->data != topNode2->left->data) return false;
            st1.push(topNode1->left);
            st2.push(topNode2->left);
        }
    }    
    if(st1.empty() - st2.empty() != 0) return false;
    return true;    
}

// 4. MIRROR TREE
void mirror(Node* node) {
    vector<vector<Node*>> levels;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int queueSize = q.size();
        vector<Node*> level;
        for(int i = 0; i < queueSize; i+=1){
            Node* currTop = q.front();
            q.pop();
            level.push_back(currTop);
            if(currTop != NULL){
                q.push(currTop->left);
                q.push(currTop->right);
            }
        }
        bool allNull = true;
        for (Node* n : level) {
            if (n != NULL) {
                allNull = false;
                break;
            }
        }
        if (allNull) break;
        levels.push_back(level);
    }    
    
    // reverse
    for(int i = 0; i < levels.size(); i+=1){
        int low = 0;
        int high = levels[i].size() - 1;
        while(high >= low){
            Node* temp = levels[i][low];
            levels[i][low] = levels[i][high];
            levels[i][high] = temp;
            low++;
            high--;
        }
    }

    // making the tree
    Node* root1 = levels[0][0];
    queue<Node*> newTree;
    newTree.push(root1);

for(int i = 1; i < levels.size(); i++){
    int j = 0;
    while(j < levels[i].size()){
        Node* parent = newTree.front();
        newTree.pop();

        // Left child
        if (levels[i][j] != NULL) {
            parent->left = new Node(levels[i][j]->data);
            newTree.push(parent->left);
        } else {
            parent->left = NULL;
        }
        j++;

        // Right child
        if (j < levels[i].size() && levels[i][j] != NULL) {
            parent->right = new Node(levels[i][j]->data);
            newTree.push(parent->right);
        } else {
            parent->right = NULL;
        }
        j++;
    }
}


    node = root1;
}

// 5. SYMMETRIC TREE
bool isSymmetricVector(vector<Node*> vec) {
    int n = vec.size();
    for(int i = 0; i < n / 2; i++) {
        Node* left = vec[i];
        Node* right = vec[n - i - 1];
        
        if(left == NULL && right == NULL) continue;
        if((left == NULL || right == NULL) || (left->data != right->data))
            return false;
    }
    return true;
}

bool isSymmetric(Node* root) {
    // in 2d array of Nodes store in level order (with NULL)
    // then compare two two
    vector<vector<Node*>> levels;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int queueSize = q.size();
        vector<Node*> level;
        for(int i = 0; i < queueSize; i+=1){
            Node* currNode = q.front();
            q.pop();
            level.push_back(currNode);
            if(currNode!=NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        bool allNull = true;
        for(Node* n : level){
            if(n!=NULL){
                allNull = false;
                break;
            }
        }
        if(allNull) break;
        levels.push_back(level);
    }        

    for(int i = 1; i < levels.size(); i+=1){
        int size = levels[i].size();
        int comparingSize = size/2;
        if(!isSymmetricVector(levels[i])) return false;
    }
    return true;



}

// // 6. BALANCED BINARY TREES
// int treeHeight(Node* root){
//     if(root==NULL) return 0;
//     queue<Node*> q;
//     int height = 0;
//     q.push(root);
//     while(!q.empty()){
//         int qHeight = q.size();
//         for(int i = 0; i < qHeight; i+=1){
//             Node* currNode = q.front();
//             q.pop();
//             if(currNode->left!=NULL) q.push(currNode->left);
//             if(currNode->right!=NULL) q.push(currNode->right);    
//         }
//         height++;
//     }
//     return height + 1;
// }

// bool isBalanced(Node* root) {
//     int height1 = treeHeight(root->left);
//     int height2 = treeHeight(root->right);
//     return abs(height1 - height2) <= 1;

// }

// int height(Node* root) {
//     if (!root) return 0;
//     return 1 + max(height(root->left), height(root->right));
// }

// bool isBalanced(Node* root) {
//     if (!root) return true; // An empty tree is balanced
    
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
    
//     // Check if current node is balanced, then check subtrees
//     return (abs(leftHeight - rightHeight) <= 1) &&
//            isBalanced(root->left) &&
//            isBalanced(root->right);
// }

// 7. For every node check if the node is sum of its immediate left and right
int isSumProperty(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        for(int i = 0; i <qHeight; i+=1){
            Node* currNode = q.front();
            q.pop();
            int sum = 0;
            int check = false;
            if(currNode->left!=NULL){
                sum+=currNode->left->data;
                q.push(currNode->left);
                check = true;
            }
            if(currNode->right!=NULL){
                sum+=currNode->right->data;
                q.push(currNode->right);
                check = true;
            }

            // check
            if(sum!=currNode->data && check){
                return 0;
            }
        }
    }
    return 1;
}

// 8. Find largest value in each level of Binary Tree
void largestLevelValue(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        int currMax = q.front()->data;
        for(int i = 0; i < qHeight; i++){
            Node* currNode = q.front();
            q.pop();
            if(currNode->data > currMax) currMax = currNode->data;
            if(currNode->left!=NULL) q.push(currNode->left);
            if(currNode->right!=NULL) q.push(currNode->right);
        }
        cout << currMax << " ";
    }
    cout << "\n";
}

// siblings gcd
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int maxBinTreeGCD(vector<vector<int>> arr, int N) {
    unordered_map<int, pair<int, int>> hashmap;
    for(int i = 0; i < arr.size(); i+=1){
        if(arr[i].size()!=0 || arr[i].size()!=1){
            if(hashmap.find(arr[i][0]) != hashmap.end()){
                hashmap[arr[i][0]].second = arr[i][1];
            }else{
                hashmap[arr[i][0]] = make_pair(arr[i][1], -1);
            }
        }
    }

    int maxGCD = -1;
    for(auto val : hashmap){
        int num1 = val.second.first;
        int num2 = val.second.second;
        maxGCD = max(GCD(num1, num2), maxGCD);
    }
    return maxGCD;
}

// 10. ZigZag traversal
void ZigZagTraversal(Node* root){
    queue<Node*> q;
    bool leftToRight = true;
    q.push(root);
    while(!q.empty()){
        vector<int> vec;
        int qHeight = q.size();
        for(int i = 0; i < qHeight; i+=1){
            Node* currNode = q.front();
            q.pop();
            vec.push_back(currNode->data);
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        if(leftToRight){
            for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        }else{
            for(int i = vec.size() - 1; i >= 0; i-=1) cout << vec[i] << " ";
        }
        leftToRight = !leftToRight;
        cout << "\n";
    }
}

// 11. sorted array to BST
Node* sortedBST(vector<int>& nums, int low, int high){
    if(low > high) return NULL;
    int mid = low + (high - low)/2;
    Node* root = new Node(nums[mid]);
    root->left = sortedBST(nums, 0, mid - 1);
    root->right = sortedBST(nums, mid + 1, nums.size() - 1);
    return root;
}

Node* sortedArrayToBST(vector<int>& nums) {
    Node* root = sortedBST(nums, 0, nums.size() - 1);
    return root;
}

int main(){
    Node* root = new Node(35);
    root->left = new Node(20);
    root->right = new Node(15);
    root->left->left = new Node(15);
    root->left->right = new Node(5);
    root->right->right = new Node(5);
    root->right->left = new Node(10);
    ZigZagTraversal(root);

    return 0;
}