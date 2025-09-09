class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr, int k, int n, int start, int count, int sum) {
        if (count==k && sum==n) {
            res.push_back(curr);
            return;
        }
        if (count>k || sum>n) return;

        for (int i=start; i<=9; i++) {
            curr.push_back(i);
            backtrack(res,curr,k,n,i+1,count+1,sum+i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res,curr,k,n,1,0,0);
        return res;
    }
};