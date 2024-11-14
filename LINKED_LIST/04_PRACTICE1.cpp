#include <iostream>

// Linked List
class Node{
public:
    int value;
    Node* next;
    Node(int value){
        this->value = value;
        this->next = NULL; 
    }
};
// Insert At Tail (HELPER FUNCTION)
void InsertAtTail(Node* &head, int data){
    Node* n = new Node(data);
    if(head==NULL){
        head = n;
        return;
    }
    Node* tempPtr = head;
    while(tempPtr->next != NULL){
        tempPtr = tempPtr->next;
    }
    tempPtr->next = n;   
}
// Traverse Linked List
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->value << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

// 1. REVERSE A LINKED LIST
void ReverseLinkedList(Node* &head){
    if(head==NULL){
        return;
    }
    Node* tempPtr1 = NULL;
    Node* tempPtr2 = head;
    Node* tempPtr3 = NULL;
    while(tempPtr2!=NULL){
        tempPtr3 = tempPtr2->next; 
        tempPtr2->next = tempPtr1;  
        tempPtr1 = tempPtr2;        
        tempPtr2 = tempPtr3;   
    }
    head = tempPtr1;
}

// 2. Delete the middle node (using this approach for countering the segmentation fault for too big files)
Node* deleteMid(Node* head) {
        // Edge case: If the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }
        
        // Initialize pointers
        Node *slow = head;
        Node *fast = head;
        Node *prev = NULL;
        
        // Use two-pointer technique to find the middle
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Remove the middle node
        if (prev != NULL) {
            prev->next = slow->next;
        }
        delete slow;
        
        return head;
    }

// REVERSE LINKED LIST IN GROUPS OF k
Node* findKthNode(Node* temp, int k){
    k-=1;
    while(temp!=NULL && k>0){
        k-=1;
        temp = temp->next;
    }
    return temp;
}

Node* ReverseInKGroups(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = NULL;
    Node* newHead = head;

    while (temp != NULL) {
        Node* kThNode = findKthNode(temp, k);
        if (kThNode == NULL) {
            // If there are less than k nodes left, do not reverse them
            if (prevLast != NULL) {
                prevLast->next = temp;
            }
            break;
        }
        Node* nextNode = kThNode->next;
        kThNode->next = NULL;
        ReverseLinkedList(temp);
        if (temp == head) {
            newHead = kThNode;
        } else {
            prevLast->next = kThNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return newHead;
}


int main(){
    Node* head = new Node(1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 7);
    InsertAtTail(head, 8);
    InsertAtTail(head, 9);
    InsertAtTail(head, 10);
    Node* r = ReverseInKGroups(head, 3);
    TraverseLinkedList(r);
    return 0;
    }