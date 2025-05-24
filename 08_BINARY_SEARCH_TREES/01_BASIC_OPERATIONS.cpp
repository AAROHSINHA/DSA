#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// helper function - to iterate inorder
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 1. INSERTION IN A BST
void InsertInBST(Node* root, int value){
    Node* toInsert = new Node(value); // this value is to be inserted
    if(root==NULL){
        root = toInsert; // if there is no BST, this becomes the root
        return;
    }

    Node* currNode = root;
    Node* prevNode = NULL;
    while(currNode!=NULL){
        if(currNode->data == value){
            return; 
            // BSTs cannot have a duplicate value
            // If the value is already existent, we reach here and return
        }else if(currNode->data < value){
            // then make prevNode to currNode and move right
            prevNode = currNode;
            currNode = currNode->right;
        }else{
            // else if value is smaller move left
            prevNode = currNode;
            currNode = currNode->left;
        }
    }

    // now we insert
    if(prevNode->data < value){
        prevNode->right = toInsert;
    }else{
        prevNode->left = toInsert;
    }

}

// 2. SEARCHING 
// Similiar algo as the insertion. Just as we find the value, return True.
// if we reach the leaf node at bottom, return false
bool searchInBST(Node* root, int value){
    Node* currNode = root;
    while(currNode!=NULL){
        if(currNode->data == value){
            return true;
        }else if(currNode->data < value){
            currNode = currNode->right;
        }else{
            currNode = currNode->left;
        }
    }
    return false;
}

// 3. DELETE 

void DeleteinBST(Node* root, int value){
    Node* currPtr = root;
    Node* prevPtr = NULL;
    bool found = false;
    while(currPtr!=NULL){
        if(currPtr->data == value){
            // delete logic
            // 1. if leaf node
            if(currPtr->left == NULL && currPtr->right == NULL){
                if(prevPtr->data < value) prevPtr->right = NULL;
                else prevPtr->left = NULL;
            }
            // 2. if  both child node
            else if(currPtr->left!=NULL && currPtr->right!=NULL){
                // finding inorder successor and replace with currnode
                // go to right then as left as possible. 
                // replace current with left most and delete the leftmost
                Node* leftPtr = currPtr->right;
                while(leftPtr->left!=NULL){
                    prevPtr = leftPtr;
                    leftPtr = leftPtr->left;
                }
                currPtr->data = leftPtr->data;
                prevPtr->left = NULL;

            }
            // 3. if only one child node
            else{
                if (currPtr->left != NULL) prevPtr->left = currPtr->left;
                else prevPtr->right = currPtr->right;
            }
            found = true;
            return;
        }else if(currPtr->data < value){
            prevPtr = currPtr;
            currPtr = currPtr->right;
        }else{
            prevPtr = currPtr;
            currPtr = currPtr->left;
        }
    }
    if(!found){
        cout << "NO SUCH ELEMENT FOUND" << endl;
    }
}

// 4. Find the minimum element in a BST
int minValue(Node* root) {
    Node* leftPtr = root;
    while(leftPtr->left!=NULL){
        leftPtr = leftPtr->left;
    }
    return leftPtr->data;
}

// 5. Find the maximum element in a BST
int maxValue(Node* root){
    Node* rightPtr = root;
    while(rightPtr->right!=NULL){
        rightPtr = rightPtr->right;
    }
    return rightPtr->data;
}

// 6. Inorder Succesor
int inOrderSuccessor(Node *root, Node *x) {
    // Case 1: x has a right subtree -> successor is the leftmost node in right subtree
    if (x->right != NULL) {
        Node* temp = x->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->data;
    }

    // Case 2: x has no right subtree -> find the lowest ancestor where x is in its left subtree
    Node* successor = NULL;
    Node* current = root;

    while (current != NULL) {
        if (x->data < current->data) {
            successor = current;
            current = current->left;
        } else if (x->data > current->data) {
            current = current->right;
        } else {
            break; // x found
        }
    }

    return (successor != NULL) ? successor->data : -1;
}

// 7. Inorder Predeccesor
int inOrderPredecessor(Node* root, Node* x){
    if(x->left!=NULL){
        Node* currPtr = x->left;
        while(currPtr->right!=NULL){
            currPtr = currPtr->right;
        }
        return currPtr->data;
    }

    // if no left subtree present
    Node* currPtr = root;
    Node* succesor = NULL;
    while(currPtr!=NULL){
        if(currPtr->data > x->data){
            currPtr = currPtr->left;
        }else if(currPtr->data < x->data){
            succesor = currPtr;
            currPtr = currPtr->right;
        }else{
            break;
        }
    }
    return (succesor == NULL) ? -1 : succesor->data;
}

// 8. FLOOR OF x
int floor(Node* root, int x) {
    Node* currPtr = root;
    Node* prevPtr = NULL;
    while(currPtr!=NULL){
        if(currPtr->data == x){
            return x;
        }else if(currPtr->data < x){
            prevPtr = currPtr;
            currPtr = currPtr->left;
        }else{
            prevPtr = currPtr;
            currPtr = currPtr->right;
        }
    }   
    return (prevPtr == NULL) ? -1 : prevPtr->data;
        
}

// 9. CHECK IF GIVE BINARY TREE IS A BST
// note - inorder of bst gives a sorted array
bool isBST(Node* root) {
    vector<int> inorder;
    stack<Node*> st;
    Node* tempPtr = root;
    while(true){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr= tempPtr->left;
        }else{
            if(st.empty()) break;
            Node* temp = st.top();
            inorder.push_back(temp->data);
            st.pop();
            tempPtr = temp->right;
        }
    }

    // check if inorder is sorted
    for(int i = 1; i < inorder.size(); i+=1){
        if(inorder[i] >= inorder[i - 1]) continue;
        return false;
    }
    return true;

        
}

// 10. Kth largest element
int KthBST(Node* root, int k){
    vector<int> inorder;
    stack<Node*> st;
    Node* tempPtr = root;
    while(true){
        if(tempPtr!=NULL){
            st.push(tempPtr);
            tempPtr= tempPtr->left;
        }else{
            if(st.empty()) break;
            Node* temp = st.top();
            inorder.push_back(temp->data);
            st.pop();
            tempPtr = temp->right;
        }
    }
    return inorder[inorder.size() - k];

}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    cout << maxValue(root) << "\n";

    return 0;
}