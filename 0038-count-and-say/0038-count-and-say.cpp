class Solution {
public:
    string nextString(string& s) {
        string res = "";
        int count = 1;

        for (int i=1; i<=s.size(); i++) {
            if (i<s.size() && s[i]==s[i-1]) {
                count++;
            } else {
                res += to_string(count) + s[i-1];
                count=1;
            }
        }

        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        int i=0;

        for (int i=1; i<n; i++) {
            res = nextString(res);
        }

        return res;
    }
};