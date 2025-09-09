class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; //stack
        int j = 0; //pop pointer

        for (int x : pushed) {
            st.push(x); //simulate push
            //keep popping while top matches popped[j]
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};