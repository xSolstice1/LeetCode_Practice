// Last updated: 07/09/2025, 21:37:39
class Solution {
public:
    void backtrack(vector<string>& res, string curr, int open, int close, int n) {
        if (curr.size()==n*2) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            backtrack(res,curr+"(",open+1,close,n);
        }
        if (close < open) {
            backtrack(res,curr+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",0,0,n);
        return res;
    }
};