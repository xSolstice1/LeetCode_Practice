class Solution {
public:
    bool memo(int i, int j, vector<vector<int>>& dp, string& s, string& p) {
        if (i >= s.length() && j >= p.length()) return true; //base case: all chars matched
        if (j >= p.length()) return false; //pattern empty earlier than s
        if (i >= s.length() && j < p.length()) { //not all characters matched
            while (j < p.length()) {
                if (p[j++] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') {
            dp[i][j] = memo(i+1,j+1,dp,s,p);
        } else if (p[j] == '*') {
            dp[i][j] = memo(i,j+1,dp,s,p) || memo(i+1,j,dp,s,p);
        } else {
            dp[i][j] = false;
        }

        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1,-1));

        return memo(0,0,dp,s,p);
    }
};