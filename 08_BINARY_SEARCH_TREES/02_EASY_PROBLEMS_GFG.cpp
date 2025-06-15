#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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

// 1. FIND THE SECOND LARGEST ELEMENT
// approach1 - by right->root->left we can get the second element
int secondLargest(Node* root){
    int elementCount = 0;
    stack<Node*> st;
    Node* tempPtr = root;
    while(true){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr = tempPtr->right;
        }else{
            if(st.empty()) return -1;
            Node* currPtr = st.top();
            st.pop();
            elementCount++;
            if(elementCount == 2){
                return currPtr->data;
            }
            tempPtr = currPtr->left;
        }
    }
    return -1;
}

// 2. Sum of k smallest
// do inorder upto k elements and get their sum
int sumKSmallest1(Node* root, int k) {
    int sum = 0;
    int n = 0;
    Node* tempPtr = root;
    stack<Node*> st;
    while(n < k){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr = tempPtr->left;
        }else{
            if(st.empty()) break;
            Node* currPtr = st.top();
            st.pop();
            n++;
            sum+=currPtr->data;
            tempPtr = currPtr->right;
        }
    }
    return sum;
}

// method 2 -> morris traversal
int sumKSmallest(Node* root, int k) {
    int sum = 0;
    int n = 0;
    Node* currPtr = root;
    while(currPtr!=NULL && n < k){
        if(currPtr->left==NULL){
            sum += currPtr->data;
            currPtr = currPtr->right;
            n++;
        }else{
            // finding the predecessor
            Node* predPtr = currPtr->left;
            while(predPtr->right!=NULL && predPtr->right!=currPtr){
                predPtr = predPtr->right;
            }

            // if no threads...
            if(predPtr->right==NULL){
                predPtr->right = currPtr;
                currPtr = currPtr->left;
            }else{
                // if threads....
                predPtr->right=NULL;
                sum+=currPtr->data;
                n++;
                currPtr = currPtr->right;
            }
        }
    }
    return sum;
}

// 3. Print BST keys in given Range 
// approach - use morris traversal. Wait until get the lower limit, then print and break after the upper limit
void printBSTRange(Node* root, int n1, int n2){
    Node* currPtr = root;
    while(currPtr!=NULL){
        if(currPtr->data > n2) break;
        if(currPtr->left==NULL){
            if(currPtr->data >= n1) cout << currPtr->data << " ";
            currPtr = currPtr->right;
        }else{
            // predecessor
            Node* predPtr = currPtr->left;
            while(predPtr->right!=NULL && predPtr->right!=currPtr){
                predPtr = predPtr->right;
            }

            // if no threads...
            if(predPtr->right == NULL){
                predPtr->right = currPtr;
                currPtr = currPtr->left;
            }else{
                // threads present
                predPtr->right = NULL;
                if(currPtr->data >= n1) cout << currPtr->data << " ";
                currPtr = currPtr->right;
            }
        }
    }
    cout << "\n";
}

// 4. BINARY SEARCH TREE -> BST keeping structure same
Node *binaryTreeToBST(Node *root) {
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

    // now we have array of inorder iteration
    // sort this array
    // again perform inorder iteration and add those elements
    sort(inorder.begin(), inorder.end());
    Node* tempPtr = root;
    stack<Node*> st;
    int index = 0;
    while(true){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr = tempPtr->left;
        }else{
            if(st.empty()) break;
            Node* currPtr = st.top();
            currPtr->data = inorder[index++];
            st.pop();
            tempPtr = currPtr->right;
        }
    }
    return root;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    printBSTRange(root, 3, 7);
    return 0;
}
