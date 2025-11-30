#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string getStackString(const std::stack<char>& s) {
    std::string result = "";
    std::stack<char> temp = s;
    while (!temp.empty()) {
        result = temp.top() + result;
        temp.pop();
    }
    return result;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";
    std::stack<char> s;

    std::cout << "Step-by-Step Conversion for: " << infix << std::endl;
    std::cout << "Token\tStack\t\tPostfix" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    for (char token : infix) {
        std::string stackContent = getStackString(s);
        std::cout << token << "\t[" << stackContent << "]\t\t" << postfix;

        if (isalpha(token)) {
            postfix += token;
            std::cout << " -> Append operand." << std::endl;
        } else if (token == '(') {
            s.push(token);
            std::cout << " -> Push '('." << std::endl;
        } else if (token == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            std::cout << " -> Pop until '('." << std::endl;
        } else if (precedence(token) > 0) {
            while (!s.empty() && precedence(s.top()) >= precedence(token)) {
                postfix += s.top();
                s.pop();
            }
            s.push(token);
            std::cout << " -> Pop higher/equal precedence, then push operator." << std::endl;
        } else {
            std::cout << " -> Ignore whitespace/invalid." << std::endl;
        }
    }

    std::cout << "End\t[" << getStackString(s) << "]\t\t" << postfix;
    std::cout << " -> Empty remaining stack." << std::endl;
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main() {
    std::string infix = "a-b*c-d/e+f";
    
    std::string postfixResult = infixToPostfix(infix);

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Final Infix: " << infix << std::endl;
    std::cout << "Final Postfix: " << postfixResult << std::endl;

    return 0;
}