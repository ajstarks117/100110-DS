#include <iostream>
#include <string>
#include <stack>

bool isBalanced(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    std::string test1 = "{[()]}";
    std::string test2 = "([)]";
    
    std::cout << isBalanced(test1) << std::endl;
    std::cout << isBalanced(test2) << std::endl;
    
    return 0;
}