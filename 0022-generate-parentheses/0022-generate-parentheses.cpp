class Solution {
public:
    void backtrack(vector<string>& res, string curr, int openPos, int closePos, int n) {
        if (curr.size() == n*2) {
            res.push_back(curr);
            return;
        }

        if (openPos < n) {
            backtrack(res,curr+"(",openPos+1,closePos,n);
        }
        if (closePos < openPos) {
            backtrack(res,curr+")",openPos,closePos+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
};