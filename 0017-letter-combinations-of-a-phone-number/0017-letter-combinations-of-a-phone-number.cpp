class Solution {
public:
    void backtrack(string digits, unordered_map<char,vector<char>> mp, string curr, vector<string>& res) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }

        char digit = digits[curr.size()];

        for (char c:mp[digit]) {
            backtrack(digits,mp,curr+c,res);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "" || digits == "1") return {};
        
        string curr = "";
        vector<string> res;
        unordered_map<char, vector<char>> mp = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };

        backtrack(digits,mp,curr,res);

        return res;
    }
};