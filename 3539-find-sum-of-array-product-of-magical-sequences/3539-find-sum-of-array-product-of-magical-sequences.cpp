class Solution {
private:
    const int MOD = 1e9 + 7; //Since the answer may be large, return it modulo 109 + 7.

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // maximum possible sum when picking m times:
        // each pick can add up to 2^(n-1)
        long long maxAdd = 1LL << (n - 1);
        long long maxSum = (long long)m * maxAdd; // inclusive max mask value

        // dp[used][sum] = total sum of products (mod MOD) for sequences of length `used`
        // with binary-sum == sum.
        vector<vector<long long>> dp(m + 1, vector<long long>(maxSum + 1, 0));
        dp[0][0] = 1; // empty sequence -> product 1

        for (int used = 0; used < m; ++used) {
            for (long long sum = 0; sum <= maxSum; ++sum) {
                long long cur = dp[used][sum];
                if (cur == 0) continue;
                for (int i = 0; i < n; ++i) {
                    long long newSum = sum + (1LL << i);
                    if (newSum <= maxSum) {
                        // multiply the product by nums[i] (sequence order matters)
                        dp[used + 1][newSum] =
                            (dp[used + 1][newSum] + (cur * (nums[i] % MOD)) % MOD) % MOD;
                    }
                }
            }
        }

        long long ans = 0;
        for (long long s = 0; s <= maxSum; ++s) {
            if (__builtin_popcountll(s) == k) {
                ans = (ans + dp[m][s]) % MOD;
            }
        }
        return (int)ans;
    }
};
