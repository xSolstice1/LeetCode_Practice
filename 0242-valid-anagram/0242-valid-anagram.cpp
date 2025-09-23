class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;

        if (s.size() != t.size()) return false;

        for (int i=0; i<s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto& itr:mp) {
            if (itr.second != 0) return false;
        }

        return true;
    }
};