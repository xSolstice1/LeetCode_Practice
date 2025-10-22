class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        for (auto& [target, originalCount] : freq) {
            int left = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin() - 1;
            
            int reachable = right - left + 1;
            int canChange = reachable - originalCount;
            
            res = max(res, originalCount + min(canChange, numOperations));
        }
        
        set<long long> candidates;
        for (int num : nums) {
            candidates.insert((long long)num - k);
            candidates.insert(num);
            candidates.insert((long long)num + k);
        }
        
        for (long long target : candidates) {
            int left = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin() - 1;
            
            int reachable = right - left + 1;
            int originalCount = freq[target];
            int canChange = reachable - originalCount;
            
            res = max(res, originalCount + min(canChange, numOperations));
        }
        
        return res;
    }
};