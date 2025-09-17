class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }
        long long rem = sum % k;
        if (rem < 0) rem += k;
        return rem;
    }
};