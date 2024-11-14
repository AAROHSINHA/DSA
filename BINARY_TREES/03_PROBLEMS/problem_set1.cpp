// 1. Count Non-leaf nodes in a binary tree

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

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

// 1. Count Non-leaf nodes in a binary tree
/*
Approach is to do the level order traversal..in the end we will have
the arr of arr so then we will calculate the total elements. Also we will have the max height.
by max height we can calculate the no of nodes there should have been and then subtract the total elements from it.
HENCE WE GET THE ANSWER
 */
int NonLeafNodes(TreeNode* root){
    if(root==NULL) return 0;
    int no_of_elems = 0;
    int tree_size = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        std::vector<int> level;
        for(int i = 0; i < size; i+=1){
            TreeNode* node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->data);
        }
        no_of_elems += level.size();
        tree_size += 1;
    }
    int max_nodes = std::pow(2, tree_size) - 1;
    return max_nodes - no_of_elems;
}

// 2. Print the immediate right node to the given key
TreeNode* nextRightNode(TreeNode* root, int key){
    // Base Case
    if(root == NULL) return new TreeNode(-1);
    std::queue<TreeNode*> qn;
    std::queue<int> ql;
    int level = 0;
    qn.push(root);
    ql.push(level);
    while(qn.size()){
        TreeNode* node = qn.front();
        int level = ql.front();
        qn.pop();
        ql.pop();
        
        // If the current node is the key
        if(node->data == key){
            // check if there are any more elements or not
            if(ql.size() == 0 || ql.front()!=level){
                return new TreeNode(-1);
            }else{
                return qn.front();
            }
        }

        // Standard BinaryTree Steps
          if (node->left != NULL)
        {
            qn.push(node->left);
            ql.push(level+1);
        }
        if (node->right != NULL)
        {
            qn.push(node->right);
            ql.push(level+1);
        }
    }
    return new TreeNode(-1);
}

// 3. Height of binary tree in O(n)
int HeightBinaryTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int lh = HeightBinaryTree(root->left);
    int rh = HeightBinaryTree(root->right);

    return std::max(lh, rh) + 1;
}

// 4. Check if balanced BinaryTree
int checkBalancedBinaryTree(TreeNode* root){
    if(root==NULL) return 0;
    int leftH = checkBalancedBinaryTree(root->left);
    int rightH = checkBalancedBinaryTree(root->right);

    if(leftH == -1 && rightH == -1){
        return -1;
    }
    if(std::abs(leftH - rightH) > 1){
        return -1;
    }

    return std::max(leftH, rightH) + 1;
}



int main(){
    TreeNode* rootNode = new TreeNode(1);
    rootNode->left = new TreeNode(2);
    rootNode->right = new TreeNode(3);
    rootNode->left->left = new TreeNode(4);
    rootNode->left->right = new TreeNode(5);
    rootNode->left->left->left = new TreeNode(6);

    std::cout << checkBalancedBinaryTree(rootNode);

    
    return 0;
}