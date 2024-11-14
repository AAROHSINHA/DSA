#include <iostream>
#include <vector>

class Queue {
private:
    int start = -1;
    int current = -1;
    int currentSize = 0;
    int size = 5;
    int q[5]; // consider a queue of size 5

public:
    // 1. push
    void push(int value) {
        if (currentSize == size) {
            std::cout << "Queue Overflow" << std::endl;
            return;
        }
        if (currentSize == 0) {
            start = 0;
            current = 0;
        } else {
            current = (current + 1) % size;
        }
        q[current] = value;
        currentSize++;
    }

    // 2. pop
    int pop() {
        if (currentSize == 0) {
            std::cout << "Queue Underflow" << std::endl;
            return -1;
        }

        int value = q[start];
        if (currentSize == 1) {
            start = -1;
            current = -1;
        } else {
            start = (start + 1) % size;
        }
        currentSize--;
        return value;
    }

    // 3. top
    int top() {
        if (currentSize != 0) {
            return q[start]; // Return the element at the front (start index)
        } else {
            std::cout << "Queue is empty" << std::endl;
            return -1; // Indicate the queue is empty
        }
    }

    // 4. size
    int getSize() {
        return currentSize;
    }

    // 5. isEmpty
    bool isEmpty() {
        return currentSize == 0;
    }

    // 6. isFull
    bool isFull() {
        return currentSize == size;
    }
};

int main() {
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "Front element: " << q.top() << std::endl;
    
    q.pop();
    std::cout << "Front element after pop: " << q.top() << std::endl;

    q.push(4);
    q.push(5);
    q.push(6);
    std::cout << "Front element after pushing 6: " << q.top() << std::endl;

    std::cout << "Queue size: " << q.getSize() << std::endl;
    std::cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << std::endl;

    return 0;
}


