#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Traverse a Doubly LinkedList
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=nullptr){
        std::cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

// Get Length of Doublyll
// Traverse a LinkedList
int getLength(Node* head){
    Node* tempPtr = head;
    int len = 0;
    while(tempPtr!=nullptr){
        len+=1;
        tempPtr = tempPtr->next;
    }
    return len;
}

// 1. Insert At Head
void InsertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// 2. Insert At End
void InsertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if (tail == nullptr) { 
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// 3. InsertAtPosition
void InsertAtPosition(Node* &head, int data, int pos){
    if(pos <= 1){
        InsertAtHead(head, data);
        return;
    }
    Node* tempPtr = head;
    for(int i = 1; i < pos-1; i++){
        if(tempPtr==nullptr){
            return;
        }
        tempPtr = tempPtr->next;
    }
    Node* newNode = new Node(data);
    newNode->next = tempPtr->next;
    tempPtr->next->prev = newNode;
    tempPtr->next = newNode;
    newNode->prev = tempPtr;

}

// DELETION OF NODE IN DOUBLY LINKED LIST
void DeleteFromHead(Node* &head){
        Node* temp = head;
        head = temp->next;
        temp->next->prev = nullptr;
        delete temp;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    InsertAtTail(head, tail, 10);
    InsertAtTail(head, tail, 20);
    InsertAtTail(head, tail, 30);
    InsertAtTail(head, tail, 40);
    InsertAtTail(head, tail, 50);
    InsertAtPosition(head, 1020, 3);
    DeleteFromHead(head);
    TraverseLinkedList(head);
    return 0;
}