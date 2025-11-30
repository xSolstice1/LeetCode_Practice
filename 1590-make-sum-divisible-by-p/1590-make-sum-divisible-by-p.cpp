class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x:nums) total+=x;

        long long goal = total%p;
        if (goal==0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        long long pref = 0;
        int res = nums.size();

        for (int i=0; i<nums.size(); i++) {
            pref = (pref+nums[i])%p;
            int req = (pref-goal+p)%p;

            if (mp.count(req)) {
                res = min(res, i-mp[req]);
            }

            mp[(int)pref]=i;
        }

        return res == nums.size() ? -1:res;
    }
};