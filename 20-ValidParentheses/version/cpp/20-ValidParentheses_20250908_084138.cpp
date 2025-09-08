// Last updated: 9/8/2025, 8:41:38 AM
class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        for (char c:s) {
            if (c == '(' || c == '[' || c == '{') {
                charStack.push(c);
            } else {
                if ((charStack.empty() || charStack.top() == '(' && c != ')') || (charStack.top() == '[' && c != ']') ||
                (charStack.top() == '{' && c != '}')) {
                    return false;
                } else {
                    charStack.pop();
                }
            }
        }

        return charStack.empty();
    }
};