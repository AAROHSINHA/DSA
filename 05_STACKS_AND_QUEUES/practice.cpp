#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 1. VALID PARENTHESIS CHECKER
bool isBalanced(string& s) {
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
        }else{
            if(st.empty()) return false;
            if((c == ']' && st.top() == '[') || (c == '}' && st.top() == '{') || (c == ')' && st.top() == '(')){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return true;
}

// 2. REVERSE A STRING USING A STACK
string reverse(const string& S) {
    stack<char> st;
    for(char c : S){
        st.push(c);
    }
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

// POSTFIX TO NORMAL
string postfixToNormal(string exp){
    stack<string> st;
    for(char c : exp){
        if(c == '+' || c == '-' || c == '*' || c == '/'){
            string second = st.top();
            st.pop();
            string first = st.top();
            st.pop();
            string newStr = "(" + first + c + second + ")";
            st.push(newStr);
        }else{
            st.push(string() + c);
        }
    }
    return st.top();
}

// delete middle element using recursion
void deleteMiddle(stack<int> st, int size, int current){
    if(current == size/2){
        st.pop();
        return;
    }

    int t = st.top();
    st.pop();
    current+=1;
    deleteMiddle(st, size, current++);
    st.push(t);
}

// postfix evaluation
int returnResult(int a, int b, string op){
    int result = 0;
    if(op == "+"){
        result = a + b;
    }else if(op == "-"){
        result = a - b;
    }else if(op == "*"){
        result = a*b;
    }else if(op == "/"){
        result = a/b;
    }
    return result;
}

int convertToInt(string num){
    int res = 0;
    int sign = 1;
    for(char c : num){
        if(c == '-'){
            sign*=-1;
            continue;
        }
        res*=10;
        res += c - '0';
    }
    return res*sign;
}

int evaluate(vector<string>& arr) {
    stack<int> st;
    for(int i = 0; i < arr.size(); i+=1){
        string curr = arr[i];
        if(curr == "+" || curr == "-" || curr == "*" || curr == "/"){
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            st.push(returnResult(num1, num2, curr));
        }else{
            st.push(convertToInt(curr));
        }
    }
    return st.top();
}

// next greater element
vector<int> nextLargerElement(vector<int>& arr) {
    stack<int> maxSt;
    vector<int> res(arr.size(), -1);
    for(int i = arr.size() - 1; i >= 0; i--){
        if(maxSt.empty()){
            res[i] == -1;
            maxSt.push(arr[i]);
        }else{
            while(!maxSt.empty() && maxSt.top() < arr[i]){
                maxSt.pop();
            }
            if(maxSt.empty()){
                res[i] = -1;
                maxSt.push(arr[i]);
                continue;
            }
            res[i] = maxSt.top();
            maxSt.push(arr[i]);
        }
    }
    return res;
}

int main(){
    vector<int> vec = {1, 3, 2, 4};
    vector<int> res = nextLargerElement(vec);
    for(int a : res){
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}
