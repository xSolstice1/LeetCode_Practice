class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        vector<bool> inc(n, false);

        for (int start = 0; start + k <= n; ++start) {
            bool ok = true;
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) {
                    ok = false;
                    break;
                }
            }
            inc[start] = ok;
        }

        for (int i = 0; i + 2 * k <= n; ++i) {
            if (inc[i] && inc[i + k]) return true;
        }

        return false;
    }
};
