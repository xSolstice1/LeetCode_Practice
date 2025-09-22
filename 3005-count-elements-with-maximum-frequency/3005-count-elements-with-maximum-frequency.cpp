class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max_freq = 0;
        int count = 0;

        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]]>max_freq) {
                max_freq = mp[nums[i]];
            }
        }

        for (auto itr : mp) {
            if (itr.second == max_freq) {
                count += itr.second;
            }
        }

        return count;
    }
};