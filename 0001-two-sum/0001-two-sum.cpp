class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for (int i=0; i<nums.size(); i++) {
            int temp = target-nums[i]; //find target's complement

            if (mp.find(temp) != mp.end()) { //look for complement in map
                return {mp[temp],i};
            }

            mp[nums[i]] = i; //map complement to index
        }

        return {};
    }
};