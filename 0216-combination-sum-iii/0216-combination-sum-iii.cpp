class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, int start, int k, int n, vector<bool>& used) {
        if (curr.size() == k && n == 0) {
            res.push_back(curr);
            return;
        }

        for (int i=start; i<=9; i++) {
            if (used[i]) continue;
            curr.push_back(i);
            used[i] = true;
            backtrack(res,curr,i,k,n-i,used);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(9,false);

        backtrack(res,curr,1,k,n,used);

        return res;
    }
};