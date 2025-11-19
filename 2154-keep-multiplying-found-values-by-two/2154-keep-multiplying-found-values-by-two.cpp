class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int res = original;
        while (find(nums.begin(),nums.end(),res) != nums.end()) {
            for (int n:nums) {
                if (n==res) {
                    res*=2;
                }
            }
        }

        return res;
    }
};