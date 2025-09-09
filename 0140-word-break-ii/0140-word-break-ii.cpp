class Solution {
public:
    void backtrack(string s, vector<string> wordDict, vector<string>& res, string curr, int start) {
        if (start == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=start; i<s.size(); i++) {
            string subStr = s.substr(start,i-start+1);
            if (find(wordDict.begin(),wordDict.end(),subStr) != wordDict.end()) {
                backtrack(s,wordDict,res,curr+subStr+(i+1 == s.size() ? "":" "),i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        
        backtrack(s,wordDict,res,"",0);
        return res;
    }
};