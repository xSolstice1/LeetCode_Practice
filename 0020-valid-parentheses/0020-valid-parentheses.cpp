class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp = {{'(',')'},{'[',']'},{'{','}'}};

        for (char c : s) {
            //if it's an opening bracket, push
            if (mp.count(c)) {
                st.push(c);
            } 
            //if it's a closing bracket, check match
            else {
                if (st.empty() || mp[st.top()] != c) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};