class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, vector<int> nums, int start) {
        res.push_back(curr);

        for (int i=start; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(res,curr,nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(res,curr,nums,0);

        return res;
    }
};