class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, vector<bool> used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (used[i]) continue;
            if (i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,res,curr,used);
            used[i]=false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(), nums.end());

        backtrack(nums,res,curr,used);

        return res;
    }
};