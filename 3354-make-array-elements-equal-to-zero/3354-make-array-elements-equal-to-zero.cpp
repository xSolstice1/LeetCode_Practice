class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        long long right = 0, left = 0;

        for (int x:nums) {
            right+=x;
        }

        for (int i=0; i<n; i++) {
            left+=nums[i];
            right-=nums[i];
            if (nums[i]!=0) continue;
            if (left==right) res+=2;
            if (abs(left-right)==1) res+=1;
        }

        return res;
    }
};