class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;

        for (int i=0; i<nums.size(); i++) {
            if (leftSum == total - nums[i] - leftSum) return i; //leftSum = rightSum
            leftSum += nums[i];
        }

        return -1;
    }
};