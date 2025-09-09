class Solution {
public:
    int climbStairs(int n) {
        // int one = 1, two = 1;

        // for (int i = 0; i < n - 1; ++i) {
        //     int temp = one;
        //     one = one + two;
        //     two = temp;
        // }

        // return one;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};