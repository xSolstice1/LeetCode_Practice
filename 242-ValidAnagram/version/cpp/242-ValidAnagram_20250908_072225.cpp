// Last updated: 9/8/2025, 7:22:25 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for (int i=0;i<s.size();i++) {
            if (s[i]!=t[i]) {
                return false;
            }
        }

        return true;
    }
};