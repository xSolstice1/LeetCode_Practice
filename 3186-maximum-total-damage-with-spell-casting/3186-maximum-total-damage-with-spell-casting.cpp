class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> damage_sum;
        for (int x : power)
            damage_sum[x] += x; // accumulate damage for same value

        vector<int> vals;
        for (auto &p : damage_sum)
            vals.push_back(p.first);

        sort(vals.begin(), vals.end());
        int n = vals.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++) {
            long long take = damage_sum[vals[i]];
            // Find last non-conflicting index
            int j = i - 1;
            while (j >= 0 && vals[i] - vals[j] <= 2)
                j--;
            if (j >= 0) take += dp[j];
            long long skip = (i > 0 ? dp[i - 1] : 0);
            dp[i] = max(skip, take);
        }
        return dp[n - 1];
    }
};
