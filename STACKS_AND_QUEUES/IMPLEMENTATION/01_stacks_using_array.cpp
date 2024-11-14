#include <iostream>
#include <vector>

class Stack{
private:
    int top = -1;
    int st[10]; // consider an array of size 10
public:
    // 1. push function
    void push(int value){
        if(top >= 10){
            std::cout << "STACK OVERFLOW" << std::endl;
            return;
        }
        top+=1;
        st[top] = value;
    }   
    // 2. pop function
    void pop(){
        if(top == -1){
            std::cout << "STACK UNDERFLOW" << std::endl;
            return;
        }
        top-=1;
    }
    // 3. top element
    int peak(){
        if(top==-1){
            std::cout << "EMPTY STACK" << std::endl;
            return -1;
        }
        return st[top];
    }
    // 4. size
    int size(){
        return top;
    }
};

int main(){
    Stack st = Stack();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    std::cout << st.peak() << std::endl;
    std::cout << st.size() << std::endl;
    st.pop();
    std::cout << st.peak() << std::endl;
    std::cout << st.size() << std::endl;
    
    return 0;
}