#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* head;
    int length;

public:
    Stack() {
        head = nullptr;
        length = 0;
    }

    // Destructor to free memory
    ~Stack() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        cout << "Stack destroyed and memory freed.\n";
    }

    // Push onto stack (insert at head)
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Pop from stack (remove from head)
    void pop() {
        if (head == nullptr) {
            cout << "STACK UNDERFLOW\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    // Return top element
    int top() {
        if (head == nullptr) {
            cout << "STACK IS EMPTY\n";
            return -1;
        }
        return head->data;
    }

    // Return size
    int size() {
        return length;
    }

    // Check if stack is empty
    bool empty() {
        return head == nullptr;
    }
};

int main(){
    return 0;
}
