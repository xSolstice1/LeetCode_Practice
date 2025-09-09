class Solution {
public:
    void backtrack(vector<int> candidates, vector<vector<int>>& res, vector<int>& curr, int target, int start) {
        if (target==0) {
            res.push_back(curr);
            return;
        }
        if (target<0) return;

        for (int i=start; i<candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates,res,curr,target-candidates[i],i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(candidates,res,curr,target,0);

        return res;
    }
};