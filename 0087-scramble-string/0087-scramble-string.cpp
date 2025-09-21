class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n!=m) return false;
        if (s1==s2) return true;
        if (n==1) return false;

        string merged = s1+" "+s2;

        if (mp.find(merged)!=mp.end()) return mp[merged];

        for (int i=1; i<n; i++) {
            bool noSwap = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));

            if (noSwap) return true;

            bool swapped = isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i));

            if (swapped) return true;
        }

        return mp[merged] = false;
    }
};