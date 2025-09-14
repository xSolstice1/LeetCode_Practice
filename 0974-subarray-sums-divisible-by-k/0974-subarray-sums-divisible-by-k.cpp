class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1; //base case sum = 0 occured once
        int cur_sum = 0, res = 0;

        for (int x:nums) {
            cur_sum += x;
            int mod = cur_sum % k;
            if (mod < 0) mod+=k;

            if (mp.find(mod) != mp.end()) {
                res += mp[mod];
            }

            mp[mod]++;
        }

        return res;
    }
};