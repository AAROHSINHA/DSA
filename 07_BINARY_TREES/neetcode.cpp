#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
void LevelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
        cout << top->data << " ";
        if(top->left!=NULL) q.push(top->left);
        if(top->right!=NULL) q.push(top->right);
    }
    cout << "\n";
}



TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        for(int i = 0; i < qHeight; i+=1){
            TreeNode* currNode = q.front();
            q.pop();
            swap(currNode->left, currNode->right);
            if(currNode->left!=NULL) q.push(currNode->left);
            if(currNode->right!=NULL) q.push(currNode->right);
        }
    }        
    return root;
}

int maxDepth(TreeNode* root) {
    // level order. just not storing anything
    if(root == NULL) return 0;
    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        for(int i = 0; i < qHeight; i+=1){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode->left!=NULL) q.push(currNode->left);
            if(currNode->right!=NULL) q.push(currNode->right);
        }
        depth+=1;
    }        
    return depth;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    return maxDepth(root->left) + maxDepth(root->right);        
}

// CHECK BALANCED BINARY TREE
int printSubTreeHeight(TreeNode* root, bool& isBalanced){
    if(!root){
        return 0;
    }
    int lh = printSubTreeHeight(root->left, isBalanced);
    int rh = printSubTreeHeight(root->right, isBalanced);
    if(abs(lh - rh) > 1) isBalanced = false;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    bool is_balanced = true;
    printSubTreeHeight(root, is_balanced);
    return is_balanced;
}

// CHECK FOR SAME TREE
bool isSameTree(TreeNode* p, TreeNode* q) {
    TreeNode *curr1 = p, *curr2 = q;
    while (curr1 && curr2) {
        if (curr1->left && curr2->left) {
            // Find predecessors
            TreeNode *pred1 = curr1->left, *pred2 = curr2->left;
            while (pred1->right && pred1->right != curr1 && 
                   pred2->right && pred2->right != curr2) {
                pred1 = pred1->right;
                pred2 = pred2->right;
            }

            // If predecessors not threaded, thread them
            if (pred1->right == NULL && pred2->right == NULL) {
                pred1->right = curr1;
                pred2->right = curr2;
                curr1 = curr1->left;
                curr2 = curr2->left;
            } 
            // If threaded, restore and compare
            else if (pred1->right == curr1 && pred2->right == curr2) {
                pred1->right = NULL;
                pred2->right = NULL;
                if (curr1->data != curr2->data) return false;
                curr1 = curr1->right;
                curr2 = curr2->right;
            } else {
                return false; // Structure mismatch
            }
        } 
        // Handle cases where one node has a left child and the other doesn't
        else if (curr1->left || curr2->left) {
            return false;
        } 
        // Compare current nodes if no left children
        else {
            if (curr1->data != curr2->data) return false;
            curr1 = curr1->right;
            curr2 = curr2->right;
        }
    }
    // Ensure both trees are fully traversed
    return !curr1 && !curr2;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;  // Edge case: empty subtree
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            // Find predecessor
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }
            // Thread or unthread
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = nullptr;
                // Check subtree match (after unthreading)
                if (curr->data == subRoot->data && isSameTree(curr, subRoot)) {
                    return true;
                }
                curr = curr->right;
            }
        } else {
            // Check subtree match
            if (curr->data == subRoot->data && isSameTree(curr, subRoot)) {
                return true;
            }
            curr = curr->right;
        }
    }
    return false;  // No match found
}

// RIGHT SIDE VIEW
vector<int> rightSideView(TreeNode* root) {
    vector<int> right;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        TreeNode* lastNode;
        for(int i = 0; i < qHeight; i+=1){
            TreeNode* currNode = q.front();
            q.pop();
            lastNode = currNode;
            if(currNode->left!=NULL) q.push(currNode->left);
            if(currNode->right!=NULL) q.push(currNode->right);
        }
        right.push_back(lastNode->data);
    }
    return right;
}

// NUMBER OF GOOD NODES
int goodNodes(TreeNode* root) {
    if(root == NULL) return 0;
    int count = 1;
    queue<pair<TreeNode*, int>> q;
    q.push({root, root->data});
    while(!q.empty()){
        int qHeight = q.size();
        for(int i = 0; i < qHeight; i+=1){
            TreeNode* currNode = q.front().first;
            int currMax = q.front().second;
            q.pop();
            if(currNode->left){
                if(currNode->left->data >= currMax){
                    count++;
                    q.push({currNode->left, currNode->left->data});
                }else{
                    q.push({currNode->left, currMax});
                }
            }
            if(currNode->right){
                if(currNode->right->data >= currMax){
                    count++;
                    q.push({currNode->right, currNode->right->data});
                }else{
                    q.push({currNode->right, currMax});
                }
            }
        }
    }   
    return count;
}

// max Path sum
int maxPathSum_rec(TreeNode* root, int& maxVal) {
    if(root==NULL) return 0;
    int leftSum = maxPathSum_rec(root->left, maxVal);
    int rightSum = maxPathSum_rec(root->right, maxVal);
    if(root->data + leftSum + rightSum > maxVal){
        maxVal = root->data + leftSum + rightSum;
    }
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxS = 0;
    maxPathSum_rec(root, maxS);
    return maxS;
}   

string serialize(TreeNode* root) {
    vector<vector<TreeNode*>> levels;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        vector<TreeNode*> level;
        for(int i = 0; i < qHeight; i+=1){
            TreeNode* currNode = q.front();
            q.pop();
            level.push_back(currNode);
            if(currNode) q.push(currNode->left);
            if(currNode) q.push(currNode->right);
        }

        bool allNull = true;
        for(TreeNode* node : level){
            if(node){
                allNull = false;
                break;
            }
        }
        if(allNull) break;
        levels.push_back(level);
        
    }   
    
    // converting to string
    string res = "";
    for(int i = 0; i < levels.size(); i+=1){
        for(int j = 0; j < levels[i].size(); j+=1){
            if(levels[i][j] == NULL){
                res += 'N';
            }else{
            int d = levels[i][j]->data;
            res+=to_string(d);
            }
            if(j < levels[i].size() - 1) res+="-";
        }
            res += "_";
        
    }
    return res;
}

TreeNode* deserialize(string data) {
    // from the string let's create the vectors
    vector<vector<TreeNode*>> levels;
    vector<TreeNode*> level;
    int i = 0;
    while(i < data.length()){
        if(data[i] == '_'){
            levels.push_back(level);
            level = {};
            i++;
        }else if(data[i]=='-'){
            i++;
        }else{
            if(data[i] == 'N'){
                level.push_back(NULL);
                i++;
                continue;
            }
            int num = 0;
            while(data[i]!='-' && data[i]!='_'){
                num*=10;
                num+=data[i] - '0';
                i++;
            }
            level.push_back(new TreeNode(num));
        }
    }    
    if(!level.empty()) levels.push_back(level);
    
    // now to convert to binary tree
    TreeNode* res = levels[0][0];
    queue<TreeNode*> q;
    q.push(res);
    i = 0;
    while(!q.empty()){
        int i_ = i + 1;
        if(i_ >= levels.size()) break;
        int j = 0;
        while(j < levels[i_].size()){
            TreeNode* currNode = q.front();
            q.pop();
            currNode->left = levels[i_][j];
            if(levels[i_][j]) q.push(levels[i_][j]);
            j++;
            currNode->right = levels[i_][j];
            if(levels[i_][j]) q.push(levels[i_][j]);
            j++;
        } 
        i+=1;
    }

    return res;
}

// Tree from preorder and inorder
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> indexes;
    for(int i = 0; i < inorder.size(); i+=1){
        indexes[inorder[i]] = i;
    }
    vector<TreeNode*> done(inorder.size(), NULL);
    TreeNode* root = new TreeNode(preorder[0]);
    done[0] = root;
    int index = 1;
    for(int i = 1; i < preorder.size(); i+=1){
        for(int j = 0; j < index; j+=1){
            int rootVal = done[j]->data;
            int curr = preorder[i];
            if(indexes[curr] < indexes[rootVal] && !done[j]->left){
                done[j]->left = new TreeNode(curr);
                done[index++] = done[j]->left;
                break;
            }
            if(indexes[curr] > indexes[rootVal] && !done[j]->right){
                done[j]->right = new TreeNode(curr);
                done[index++] = done[j]->right;
                break;
            }
        }
    }

    // seriralize
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qHeight = q.size();
        for(int i = 0; i < qHeight; i+=1){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode->left) q.push(currNode->left);
            else currNode->left = NULL;
            if(currNode->right) q.push(currNode->right);
            else currNode->right = NULL;
        }
    }

    return root;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> preorder = {1,2,4, 5, 7, 3, 6, 8};
    vector<int> inorder = {4, 2, 7, 5, 1, 8, 6, 3};
    LevelOrderTraversal(buildTree(preorder, inorder));
    return 0;
}