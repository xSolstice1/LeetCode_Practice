class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& res, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums,curr,res,used);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        vector<bool> used(nums.size(),false);

        backtrack(nums,curr,res,used);
        return res;
    }
};