class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // bruteforce, TLE
        // long long res = 0;

        // for (int i=0; i<nums.size(); i++) {
        //     for (int j=i+1; j<nums.size(); j++) {
        //         if (lower <= nums[i] + nums[j] && nums[i] + nums[j] <= upper) {
        //             res++;
        //         }
        //     }
        // }
        
        // return res;

        //binary search?
        sort(nums.begin(),nums.end());
        long long res = 0;

        for (int i=0; i<nums.size(); i++) {
            auto lowerBound = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);
            auto upperBound = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);

            res += upperBound - lowerBound; //number of valid pairs
        }

        return res;
    }
};