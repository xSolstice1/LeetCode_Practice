class Solution {
public:
    void backtrack(int& res, vector<int>& nums, int k, int i, vector<int>& curr) {
        if (i == nums.size()) {
            if (!curr.empty()) res++;
            return;
        }

        backtrack(res,nums,k,i+1,curr);

        bool isValid = true;

        for (int x:curr) {
            if (abs(x-nums[i])==k) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            curr.push_back(nums[i]);
            backtrack(res,nums,k,i+1,curr);
            curr.pop_back();
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = 0;
        vector<int> curr;

        backtrack(res,nums,k,0,curr);

        return res;
    }
};