#include <iostream>
#include <stack>
#include <map>
using std::string;

#include <string>
#include <algorithm>

std::string reverseExpression(const std::string& expression) {
    std::string reversed = expression;
    std::reverse(reversed.begin(), reversed.end());

    // Correct the brackets after reversing
    for (char& ch : reversed) {
        if (ch == '(') {
            ch = ')';
        } else if (ch == ')') {
            ch = '(';
        }
    }

    return reversed;
}


string PostfixToInfix(string expression){
    std::stack<string> st1;
    std::map<char, int> operators = {{'+', 1}, {'-', 1}, {'*', 1}, {'/', 1}};
    for(int i = 0; i < expression.length(); i+=1){
        if(operators[expression[i]] > 0){
            std::string current = "";
            current += '(';
            std::string top1 = st1.top();
            st1.pop();
            std::string top2 = st1.top();
                st1.pop();
            current+=top1;
            current+=expression[i];
            current+=top2;
            current+=')';
            st1.push(current);
        }else{
            char c = expression[i];
            std::string str = std::string(1, c);
            st1.push(str);
        }
    }

    return reverseExpression(st1.top());
}


int main(){
    string expression = "AB-DE+F*/";
    string output = PostfixToInfix(expression);
    std::cout << output << std::endl;
    return 0;
}