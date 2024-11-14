#include <iostream>
#include <stack>

// 1. check balanced parenthesis
#include <stack>
#include <string>

bool BalancedParenthesis(std::string str) {
    std::stack<char> st;
    
    for (char i : str) {
        // Push opening brackets onto the stack
        if (i == '(' || i == '[' || i == '{') {
            st.push(i);
        } 
        else if (i == ')' || i == ']' || i == '}') {
            if (st.empty()) {
                return false;
            }
            
            char last_opening = st.top();
            if ((i == ')' && last_opening == '(') || 
                (i == '}' && last_opening == '{') || 
                (i == ']' && last_opening == '[')) {
                st.pop();  
            } else {
                return false;  
            }
        }
    }
    
    return st.empty();
}



int main(){
    std::string str = "()";
    bool ans = BalancedParenthesis(str);
    std::string out = (ans) ? "True" : "False";
    std::cout << out << std::endl;
    return 0;
}