#include <iostream>

// Linked List
class Node{
public:
    int val;
    Node* next;
    Node(int data){
        this->val = data;
        this->next = NULL;
    }

};

// 1. traverse Linked List
void TraverseLinkedList(Node* head){
    Node* tempPtr = head;
    while(tempPtr!=NULL){
        std::cout << tempPtr->val << std::endl;
        tempPtr = tempPtr->next;
    }
}

// Stack Using Linked List
class Stack{
private:
    Node* top = NULL;
    int currentSize = 0;
public:
    // 1. push
    void push(int data){
        Node* newNode = new Node(data);
        if(top == NULL){
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;
        }
        this->currentSize+=1;
    }

    // 2. pop
    int pop(){
        if(top == NULL){
            std::cout << "STACK UNDERFLOW" << std::endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->val;
        top = top->next;
        delete temp;
        this->currentSize -= 1;
        return value;
    }

    // 3. peak
    int peak(){
        if(top!=NULL){
            return top->val;
        }else{
            return -1;
        }
    }

    // 4. current size
    int size(){
        return this->currentSize;
    }
};

int main(){
    // Node* head = new Node(1);
    // head->next = new Node(3);
    // head->next->next = new Node(5);
    // head->next->next->next = new Node(7);
    // head->next->next->next->next = new Node(9);
    // TraverseLinkedList(head);
    Stack st = Stack();
    st.push(5);
    st.push(10);
    st.push(15);
    std::cout << st.peak() << std::endl;
    std::cout << st.size() << std::endl;
    st.pop();
    std::cout << st.peak() << std::endl;
    std::cout << st.size() << std::endl;
    return 0;
}