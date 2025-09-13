class Solution {
public:
    // backtrack causes TLE
    // void expand(vector<int>& nums, int& res, int index, int curr) {
    //     if (index == nums.size()) return;
    //     curr *= nums[index];
    //     res = max(curr,res);
    //     expand(nums,res,index+1,curr);
    // }
    int maxProduct(vector<int>& nums) {
        // backtrack causes TLE
        // int res = INT_MIN;
        
        // for (int i=0; i<nums.size(); i++) {
        //     expand(nums,res,i,1);
        // }

        // return res;

        // approach 2 - DP
        int n = nums.size();
        int res = nums[0], minP = nums[0], maxP = nums[0];

        for (int i=1; i<nums.size(); i++) { //start from 1 as we defined the 3 variables as nums[0]
            if (nums[i] < 0) swap(minP,maxP); //check negs

            minP = min(nums[i],minP*nums[i]);
            maxP = max(nums[i],maxP*nums[i]);

            res = max(res,maxP);
        }

        return res;
    }
};