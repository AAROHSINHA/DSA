#include <iostream>

class Node{
public:
    int val;
    Node* next;

    Node(int value){
        this->val = value;
        this->next = NULL;
    }
};

// Traverse Linked List
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->val << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}
// Insert At Tail
void InsertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    Node* tempPtr = head;
    while(tempPtr->next!=NULL){
        tempPtr = tempPtr->next;
    }
    tempPtr->next = n;
}

//////////////////////////////////
// REVERSE IN K GROUP
//////////////////////////////////
void ReverseLinkedList(Node* &head){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr = NULL;
    while(currPtr!=NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    head = prevPtr;
}

Node* ReturnKthNode(Node* head, int k){
    Node* temp = head;
    for(int i = 1; i < k; i+=1){
        if(temp!=NULL){
            temp = temp->next;
        }else{
            break;
        }
    }
    return temp;
}

Node* reverseKGroup(Node* head, int k) {
    Node* tempPtr = head;
    Node* prev_group = NULL;
    Node* current_group = NULL;
    Node* next_group = NULL;
    while(tempPtr!=NULL){
        current_group = tempPtr;
        Node* end_of_current_group = ReturnKthNode(tempPtr, k);
        if(end_of_current_group == NULL){
             if (prev_group == NULL) {
                return head;
            } else {
                prev_group->next = tempPtr;
                break;
            }
        }
        next_group = end_of_current_group->next;
        end_of_current_group->next = NULL;
        ReverseLinkedList(current_group);
        if(prev_group == NULL){
            head = current_group;
        }else{
            prev_group->next = current_group;
        }
        prev_group = tempPtr;
        tempPtr = next_group;
    }
    return head;
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
    TraverseLinkedList(head);
    ReturnKthNode(head, 3);
    TraverseLinkedList(head);
    return 0;
}

/*
void ReverseLinkedList(Node* &head){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr = NULL;
    while(currPtr!=NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    head = prevPtr;
}
Node* findKthNode(Node* temp, int k){
    for(int i = 0; i < k; i+=1){
        if(temp!=NULL){
            temp = temp->next;
        }else{
            break;
        }
    }
    return temp;
}

Node* ReverseKGroups(Node* head, int k) {
    Node* temp = head;
    Node* nextGroup = NULL;
    Node* prevGroup = NULL;

    while (temp != NULL) {
        Node* kthNode = findKthNode(temp, k);
        if (kthNode == NULL) {
            if (prevGroup != NULL) {
                prevGroup->next = temp;
            }
            break;
        }
        nextGroup = kthNode->next;
        kthNode->next = NULL; // Fix: Terminate the current reversed segment
        ReverseLinkedList(temp);

        if (temp == head) {
            head = kthNode;
        } else {
            prevGroup->next = kthNode; // Fix: Link the end of previous segment to the start of the reversed segment
        }

        prevGroup = temp;
        temp = nextGroup;
    }

    return head;
}

*/