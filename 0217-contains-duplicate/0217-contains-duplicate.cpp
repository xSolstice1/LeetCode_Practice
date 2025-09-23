class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int x:nums) {
            mp[x]++;
        }

        for (auto itr:mp) {
            if (itr.second > 1) {
                return true;
            } 
        }

        return false;
    }
};