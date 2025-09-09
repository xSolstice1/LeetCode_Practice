class Solution {
public:
    bool isValid(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    void backtrack(string s, vector<vector<string>>& res, vector<string>& curr, int start) {
        if (start == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=start; i<s.size(); i++) {
            string subStr = s.substr(start,i-start+1);
            if (isValid(subStr)) {
                curr.push_back(subStr);
                backtrack(s,res,curr,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;

        backtrack(s,res,curr,0);

        return res;
    }
};