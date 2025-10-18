class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_set<int> used;
        int curr = INT_MIN;

        for (int x:nums) {
            int candidate = max(x-k,curr+1);
            if (candidate <= x+k) {
                used.insert(candidate);
                curr = candidate;
            }
        }

        return used.size();
    }
};