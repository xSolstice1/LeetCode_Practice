class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) res.push_back(curr);
        if (target < 0) return;

        for (int i=start; i<candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i,curr,res); //backtrack
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        backtrack(candidates,target,0,curr,res);

        return res;
    }
};