class Solution {
public:
    bool isAnagram(string s, string t) {
        // can we use fixed size array instead? try approach 2
        // unordered_map<char,int> mp;

        // if (s.size() != t.size()) return false;

        // for (int i=0; i<s.size(); i++) {
        //     mp[s[i]]++;
        //     mp[t[i]]--;
        // }

        // for (auto& itr:mp) {
        //     if (itr.second != 0) return false;
        // }

        // return true;

        // fixed array
        if (s.size() != t.size()) return false;

        int count[26] = {0}; //26 alphabets a-z

        for (int i=0; i<s.size(); i++) {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for (int i=0; i<26; i++) {
            if (count[i]!=0) return false;
        }

        return true;
    }
};