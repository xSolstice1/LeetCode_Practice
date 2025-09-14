class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), pref = 1, suff = 1;
        vector<int> res(n,1);

        for (int i=0; i<nums.size(); i++) {
            res[i] *= pref;
            pref *= nums[i];

            res[n-i-1] *= suff;
            suff *= nums[n-i-1];
        }

        return res;
    }
};
