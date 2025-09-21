class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = n-1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total==0) {
                    res.push_back({nums[i],nums[left++],nums[right--]});
                    while (left<right && nums[left]==nums[left-1]) left++;
                    while (left<right && nums[right]==nums[right+1]) right--;
                } else if (total<0) {
                    left++;
                } else {
                    right--;
                }
            } 
        }
        return res;
    }
};