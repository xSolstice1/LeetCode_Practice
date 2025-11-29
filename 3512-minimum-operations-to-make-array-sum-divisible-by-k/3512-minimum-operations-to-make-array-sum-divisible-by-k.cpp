class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long rem = sum % k;
        if (rem < 0) rem += k;
        return rem;
    }
};