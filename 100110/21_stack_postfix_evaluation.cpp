#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <stdexcept>

int evaluatePostfix(std::string expression) {
    std::stack<int> st;
    
    for (char c : expression) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (st.size() < 2) {
                throw std::invalid_argument("Invalid postfix expression: not enough operands");
            }
            
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            
            int result;
            if (c == '+') {
                result = operand1 + operand2;
            } else if (c == '-') {
                result = operand1 - operand2;
            } else if (c == '*') {
                result = operand1 * operand2;
            } else if (c == '/') {
                if (operand2 == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                result = operand1 / operand2;
            } else {
                continue;
            }
            
            st.push(result);
        }
    }
    
    if (st.size() != 1) {
        throw std::invalid_argument("Invalid postfix expression: too many operands");
    }
    
    return st.top();
}

int main() {
    std::string expression1 = "231*+9-";
    std::string expression2 = "562/+";
    
    try {
        int result1 = evaluatePostfix(expression1);
        std::cout << result1 << std::endl; 

        int result2 = evaluatePostfix(expression2);
        std::cout << result2 << std::endl; 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}