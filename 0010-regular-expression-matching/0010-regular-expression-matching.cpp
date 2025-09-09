class Solution {
//recursive+memo dp
public:
    string s, p;
    vector<vector<int>> memo; //unvisited:-1, false: 0, true: 1
    
    bool dp(int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        
        bool ans;
        if (j == p.size()) {
            ans = (i == s.size());
        } else {
            bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            
            if (j + 1 < p.size() && p[j+1] == '*') {
                ans = dp(i, j+2) || (firstMatch && dp(i+1, j));
            } else {
                ans = firstMatch && dp(i+1, j+1);
            }
        }
        
        memo[i][j] = ans;
        return ans;
    }
    
    bool isMatch(string s_, string p_) {
        s = s_;
        p = p_;
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0);
    }
};
