class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int cur_sum = 0;

        for (int i=0; i<nums.size(); i++) {
            cur_sum += nums[i];
            int mod = cur_sum % k;
            if (mod < 0) mod += k;

            if (mp.find(mod) != mp.end() && i - mp[mod] >= 2) {
                return true;
            }

            if (mp.find(mod) == mp.end()) {
                mp[mod] = i;
            }
        }

        return false;
    }
};