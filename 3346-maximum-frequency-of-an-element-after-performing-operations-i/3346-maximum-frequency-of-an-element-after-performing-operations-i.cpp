class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        for (auto& [target, count] : freq) {
            ans = max(ans, count);
            
            int left = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin() - 1;
            
            int canConvert = right - left + 1;
            int converted = min(canConvert - count, numOperations);
            ans = max(ans, count + converted);
        }
        
        for (int i = 0; i < n; i++) {
            for (int target : {nums[i] - k, nums[i] + k}) {
                if (target < 1) continue;
                
                int left = lower_bound(nums.begin(), nums.end(), target - k) - nums.begin();
                int right = upper_bound(nums.begin(), nums.end(), target + k) - nums.begin() - 1;
        
                int canConvert = right - left + 1;
                int alreadyAt = freq[target];
                int converted = min(canConvert - alreadyAt, numOperations);
                ans = max(ans, alreadyAt + converted);
            }
        }
        
        return ans;
    }
};