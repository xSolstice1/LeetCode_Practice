class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // runtime O(n), not ideal
        // int r = nums.size()-1, l = 0;

        // while (l<=r) {
        //     if (nums[l]==target && nums[r]==target) {
        //         return {l,r};
        //     }
        //     if (nums[l]==target) {
        //         r--;
        //     } else if (nums[r]==target) {
        //         l++;
        //     } else {
        //         r--;
        //         l++;
        //     }   
        // }

        // return {-1,-1};

        int n = nums.size();
        int left = 0, right = n-1, indexLeft = -1, indexRight = -1;

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (nums[mid]==target) {
                indexLeft = mid;
                right = mid-1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        left = 0;
        right = n-1;

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (nums[mid]==target) {
                indexRight = mid;
                left = mid+1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return {indexLeft,indexRight};
    }
};