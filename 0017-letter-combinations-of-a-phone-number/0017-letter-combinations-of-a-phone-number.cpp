class Solution {
public:
    void backtrack(vector<string>& res, string& w, string& digits, int idx, unordered_map<char,string>& mp) {
        if (w.size() == digits.size()) {
            res.push_back(w);
            return;
        }

        string letters = mp[digits[idx]];
        for (char c : letters) {
            w.push_back(c);
            backtrack(res, w, digits, idx+1, mp);
            w.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char,string> mp = {
            {'2',"abc"}, {'3',"def"},
            {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"},
            {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };

        vector<string> res;
        string w;
        backtrack(res, w, digits, 0, mp);
        return res;
    }
};
