class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 0;

        for (int i=0; i<nums.size(); i++) {
            if (i>canReach) {
                return false;
            }

            canReach = max(canReach, i+nums[i]); 
        }

        return true;
    }
};

// i = 0,1,2,3,4
// nums[i] = 2,3,1,1,4
// canReach = 2,4,4,4,8

// i = 0,1,2,3,4
// nums[i] = 3,2,1,0,4
// canReach = 3,3,3,3,8