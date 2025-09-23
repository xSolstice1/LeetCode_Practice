class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (int i=0; i<strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (auto& itr:mp) {
            res.push_back(itr.second);
        }

        return res;
    }
};