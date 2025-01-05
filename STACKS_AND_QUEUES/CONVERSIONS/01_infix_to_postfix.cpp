#include <iostream>
#include <stack>
#include <map>
using std::string;

string InfixToPostfix(string expression){
    std::stack<char> st1;
    std::string ans = "";
    std::map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}, {'(', 1}, {')', 1}};

    // starting iteration
    for(int i = 0; i < expression.length(); i+=1){
        char c = expression[i];
        if(priority[c] == 0){
            ans += c;
        }else{
            if(st1.empty() || c == '('){
                st1.push(c);
            }else{
                if(c == ')'){
                    while(!st1.empty() && st1.top() != '('){
                        ans+=st1.top();
                        st1.pop();
                    }
                    st1.pop();
                }else if(priority[c] > priority[st1.top()]){
                    st1.push(c);
                }else{
                    while(!st1.empty() && priority[c] < priority[st1.top()]){
                        ans+=st1.top();
                        st1.pop();
                    }
                    st1.push(c);
                }
            }
        }
    }

    while(!st1.empty()){
        ans+=st1.top();
        st1.pop();
    }

    return ans;
}

int main(){
    string exp = "a+b*(c^d-e)";
    string out = InfixToPostfix(exp);
    std::cout << out << std::endl;

    return 0;
}