// Last updated: 9/8/2025, 7:27:23 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s;

        // for (int x:nums) {
        //     s.insert(x);
        // }

        // nums.assign(s.begin(),s.end());

        // return nums.size();

        if (nums.empty()) {
            return 0;
        }

        int j = 1;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[j-1]) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};