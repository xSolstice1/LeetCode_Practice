// Last updated: 9/7/2025, 9:22:20 PM
class Solution {
public:
    void backtrack(vector<int> candidates, vector<vector<int>>& res, vector<int>& curr, int start, int target) {
        if (target==0) {
            res.push_back(curr);
            return;
        }
        if (target<0) return;

        for (int i=start; i<candidates.size(); i++) {
            if (i>start && candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates,res,curr,i+1,target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,res,curr,0,target);

        return res;
    }
};