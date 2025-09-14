class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, lastPos = 0, reach = 0;

        for (int i=0; i<nums.size()-1; i++) {
            reach = max(reach, i+nums[i]);

            if (i == lastPos) {
                res++;
                lastPos = reach;
            }
        }

        return res;
    }
};