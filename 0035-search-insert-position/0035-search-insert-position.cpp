class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // int index = 0;

        // for (int i=0;i<nums.size();i++) {
        //     if (nums[i] == target) {
        //         return i;
        //     }
        //     else if (nums[i] < target) {
        //         index++;
        //     }
        // }

        // return index;

        int n = nums.size();
        int left = 0, right = n-1;

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid]>target) {
                right=mid-1;
            } else {
                left=mid+1;
            }
        }

        return left;        
    }
};