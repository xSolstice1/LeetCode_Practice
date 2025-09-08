// Last updated: 9/8/2025, 8:21:56 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return n;
        }

        int j = 2;

        for (int i=2; i<n; i++) {
            if (nums[i] != nums[j-2]) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};