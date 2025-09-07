// Last updated: 9/8/2025, 7:25:07 AM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, ans=0;
        unordered_set<char> seen;

        for (int r=0; r<s.size(); r++) {
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};