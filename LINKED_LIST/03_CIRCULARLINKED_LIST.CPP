#include <iostream>

// The structure of class for the circular linked list is same as the singly linked list.
// just the lsat node points to the first head node.
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=nullptr){
            delete next;
            next = nullptr;
        }
        std::cout << " Memory is fre for node with this data " << value << std::endl;
    }
};

void TraverseCircularLinkedList(Node* tail){
    // as the tail points to the first element, start from tail, keep on traversing and printing
    // then when we again reach at the rail, stop the loop and printing
    Node* temp = tail;
    std::cout << tail->data << " "; // prints the tail element (as if ll has one node, this will print that)
    while(tail->next != temp){
        tail = tail->next;
        std::cout << tail->data << " ";
        
    }
    std::cout << std::endl;
}

// 1. Insert By a given value
// -> In circular linked list, we do not need head ptr as the ll is circular, so we use the tail
// using tail, we can access the head, as tail points to head. And of course using tail we can use the last node :)
void InsertNode(Node* &tail, int element, int data){
    // base case -> empty list (tail == NULL)
    //           -> here we create a new node and it points to yourself
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        // make circular
        newNode->next = newNode;
        return;
    }

    /// non-empty list
    Node* current = tail;
    while(current->data!=element){
        if(current==NULL){
            return;
        }
        current = current->next;
    }

    Node* temp = new Node(data);
    temp->next = current->next;
    current->next = temp;

}

// 2. Delete

int main(){
    Node* tail = NULL;
    InsertNode(tail, 5, 3);
    InsertNode(tail, 3, 4);
    InsertNode(tail, 4, 5);
    InsertNode(tail, 5, 6);
    InsertNode(tail, 6, 7);
    TraverseCircularLinkedList(tail);
    return 0;
}