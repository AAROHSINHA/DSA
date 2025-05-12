    #include <iostream>
    #include <vector>
    using namespace std;

    // USING ARRAYS TO CREATE A STACK
    class Stack{
    private:
        int arr[100];
        int currLen;
    public:
        Stack(){
            currLen = 0;
        }

        // 1. push
        void push(int data){
            if(currLen >= 100){
                cout << "STACK OVERFLOW" << "\n";
                return;
            }
            arr[currLen] = data;
            currLen+=1; 
        }

        // 2. top
        int top(){
            if(currLen > 0){
                return arr[currLen - 1];
            }
            return -1;
        }

        // 3. size
        int size(){
            return currLen;
        }

        // 4. pop
        void pop(){
            if(currLen <= 0){
                cout << "STACK UNDERFLOW" << "\n";
                return;
            }
            currLen-=1;
        }

        // 5. empty
        bool empty(){
            return currLen == 0;
        }
    };

    // USING ARRAYS TO CREATE QUEUES
    class Queue{
    private:
        int arr[100];
        int currLen;
        int topPtr;
    public:
        Queue(){
            currLen = 0;
            topPtr = -1;
        }

        // 1. push
        void push(int data){
            if(currLen > 100){
                cout << "QUEUE OVERFLOW!!" << "\n";
                return;
            }

            if(currLen == 0){
                arr[currLen] = data;
                currLen++;
                topPtr = 0;
                return;
            }
            arr[currLen] = data;
            currLen++;
        }
        
        // 2. top
        int top(){
            return arr[topPtr];
        }

        // 3. pop
        void pop(){
            if(currLen <= 0){
                cout << "QUEUE UNDERFLOW" << "\n";
                return;
            }

            topPtr++;
            topPtr%=100;
        }


        // 4. size
        int size(){
            return currLen;
        }

        // 5. empty
        bool empty(){
            return currLen == 0;
        }
    };

    int main(){
        Queue q = Queue();
        q.push(10);
        q.push(20);
        q.push(30);
        cout << q.top() << "\n";
        q.pop();
        cout << q.top() << "\n";
        return 0;
    }
