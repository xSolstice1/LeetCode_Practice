class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // unordered_set<int> used;
        int res = 0;
        int curr = INT_MIN;

        for (int x:nums) {
            if (x+k<=curr) continue;
            int candidate = max(x-k,curr+1);
            if (candidate <= x+k) {
                res++;
                curr = candidate;
            }
        }

        return res;
    }
};