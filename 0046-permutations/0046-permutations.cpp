class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int> nums, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (used[i]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            backtrack(res,curr,nums,used);
            used[i] = false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(),false);

        backtrack(res,curr,nums,used);

        return res;
    }
};