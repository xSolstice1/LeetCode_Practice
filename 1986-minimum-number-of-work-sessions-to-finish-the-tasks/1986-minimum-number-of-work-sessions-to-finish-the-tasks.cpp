class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<vector<int>> dp(1 << n, vector<int>(sessionTime + 1, -1));
        
        function<int(int,int)> solve = [&](int mask, int time) {
            if (mask == (1 << n) - 1) return time > 0 ? 1 : 0;
            if (dp[mask][time] != -1) return dp[mask][time];
            
            int ans = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    if (time + tasks[i] <= sessionTime) {
                        ans = min(ans, solve(mask | (1 << i), time + tasks[i]));
                    } else {
                        ans = min(ans, 1 + solve(mask | (1 << i), tasks[i]));
                    }
                }
            }
            return dp[mask][time] = ans;
        };
        
        return solve(0, 0);
    }
};