class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        for (char c:s) {
            if (c == '(' || c == '[' || c == '{') { //open parenthesis
                charStack.push(c);
            } else {
                //check for false conditions (i.e. mismatch closing parenthesis)
                if ((charStack.empty() || charStack.top() == '(' && c != ')') || (charStack.top() == '[' && c != ']') ||
                (charStack.top() == '{' && c != '}')) {
                    return false;
                } else {
                    charStack.pop(); //parenthesis closed
                }
            }
        }

        return charStack.empty(); //everything closed?
    }
};