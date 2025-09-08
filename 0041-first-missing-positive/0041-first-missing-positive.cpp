class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            //while number = positive and within range (1,n), swap into correct pos
            while (nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i]) {
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        for (int i=0; i<n; i++) {
            //find first number not in correct position (nums[i]==i+1)
            if (nums[i]!=i+1) {
                return i+1;
            }
        }

        return n+1;
    }
};