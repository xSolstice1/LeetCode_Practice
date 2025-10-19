class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int curr=0;
        int ans=INT_MAX;
        
        for (int r=0; r<nums.size(); r++) {
            curr+=nums[r];
            while (curr >= target) {
                curr-=nums[l];
                ans=min(ans,r-l+1);
                l++;
            }
        }

        return ans==INT_MAX ? 0:ans;
    }
};