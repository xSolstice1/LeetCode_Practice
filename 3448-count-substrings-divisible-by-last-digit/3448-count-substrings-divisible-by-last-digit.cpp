class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        
        //initialize dp vector of [index][last digit of substr][remainder/modulo after dividing substr by last digit]
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(10, vector<int>(10)));

        //loop through string s
        for (int i=1; i<=n; i++) {
            int d = s[i-1] - '0'; //char to digit
            for (int j=1; j<=9; j++) { // nums 1-9
                for (int k=0; k<j; k++) { //loop through all possible remainders
                    dp[i][j][((k*10)+d)%j] += dp[i-1][j][k];
                }
                dp[i][j][d%j]++;
            }
            ans += dp[i][d][0]; //update count for all s[i]%d=0
        }
        return ans;
    }
};