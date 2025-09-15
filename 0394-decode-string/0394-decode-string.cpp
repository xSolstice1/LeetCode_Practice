class Solution {
public:
    string decodeString(string s) {
        stack<int> cStack; //stack of count of chars
        stack<string> sStack; //stack of strings
        string curr = ""; //current string
        int count = 0; //count of chars

        for (char c:s) {
            if (isdigit(c)) {
                count = count*10+(c-'0');
            } else if (c == '[') {
                cStack.push(count);
                sStack.push(curr);
                count = 0;
                curr = "";
            } else if (c == ']') {
                string temp = curr;
                int num = cStack.top(); cStack.pop();
                curr = sStack.top(); sStack.pop();
                while (num--) {
                    curr+=temp;
                }
            } else {
                curr+=c;
            }
        }

        return curr;
    }
};