#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

// Traverse a LinkedList
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=nullptr){
        std::cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

// 1. Insert At Head
void InsertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// 2. Insert At Tail
void InsertAtTail(Node* &head, int data){
    Node* temp = new Node(data);
    Node* tempPtr = head;
    if(head==nullptr){
        head = temp;
        return;
    }

    while(tempPtr->next!=nullptr){
        tempPtr = tempPtr->next;
    }
    tempPtr->next = temp;
}

// 3. Insert At an Arbitrary position
void InsertLinkedList(Node* &head, int data, int k){
    Node* newNode = new Node(data);
    Node* tempPtr = head;
    for(int i = 1; i < k-1; i+=1){
        if(tempPtr == nullptr){
            return;
        }
        tempPtr = tempPtr->next;
    }
    if(k <= 1){
        InsertAtHead(head, data);
    }
    if(tempPtr->next==NULL){
        tempPtr->next = newNode;
        return;
    }
    newNode->next = tempPtr->next;
    tempPtr->next = newNode;
}

// 4. Delete Node in LinkedList
void deleteLinkedList(Node* &head, int pos){
    if(pos==0){
        Node* h = head;
        head = head->next;
        delete h;
        return;
    }
    Node* tempPtr = head;
    for(int i = 1; i < pos-1; i+=1){
        if(tempPtr==NULL){
            return;
        }
        tempPtr = tempPtr->next;
    }
    Node* tempNode = tempPtr->next;
    tempPtr->next = tempNode->next;
    delete tempNode;
}

int main(){
    Node* head = new Node(5);
    InsertAtTail(head, 10);
    InsertAtTail(head, 15);
    InsertAtTail(head, 20);
    InsertAtTail(head, 25);
    deleteLinkedList(head, 3);
    TraverseLinkedList(head);
    return 0;
}