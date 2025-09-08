class Solution {
public:
    void backtrack(vector<int> candidates, int target, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (target==0) {
            res.push_back(curr);
            return;
        }
        if (target<0) return;

        for (int i=start; i<candidates.size(); i++) {
            if (i>start && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1,curr,res); //backtrack
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;

        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,curr,res);

        return res;
    }
};