class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //to store pref sum counts
        mp[0] = 1; //base case sum = 0 occurs once
        int cum_sum = 0, res = 0;

        for (int x:nums) {
            cum_sum += x;

            //if cum_sum-k exist in map, add frequency to res
            if (mp.find(cum_sum-k) != mp.end()) {
                res += mp[cum_sum-k];
            }

            //update map with cum sum freq
            mp[cum_sum]++;
        }

        return res;
    }
};