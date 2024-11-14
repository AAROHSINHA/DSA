#include <iostream>

class Node {
public:
    int val;
    Node* next;
    Node(int data) {
        this->val = data;
        this->next = NULL;
    }
};

class Queue {
private:
    Node* start = NULL;
    Node* end = NULL;
    int currentSize = 0;

public:
    // 1. push
    void push(int data) {
        Node* newNode = new Node(data);
        if (start == NULL && end == NULL) {
            start = newNode;
            end = start;
        } else {
            end->next = newNode;
            end = newNode;  // Update end to the new node
        }
        currentSize++;
    }

    // 2. pop
    int pop() {
        if (start == NULL) {
            return -1;  // Queue is empty
        }
        Node* temp = start;
        start = start->next;
        int value = temp->val;
        delete temp;  // Delete the old start node (temp)
        currentSize--;
        return value;
    }

    // 3. peak
    int peak() {
        if (start == NULL) {
            return -1;  // Queue is empty
        }
        return start->val;
    }

    // 4. size
    int size() {
        return currentSize;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Peak: " << q.peak() << std::endl;  // Should print 10
    std::cout << "Size: " << q.size() << std::endl;  // Should print 3

    q.pop();  // Removes 10
    std::cout << "Peak after pop: " << q.peak() << std::endl;  // Should print 20
    std::cout << "Size after pop: " << q.size() << std::endl;  // Should print 2

    return 0;
}
