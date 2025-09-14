class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //voting system approach
        int count = 0, res = 0;

        for (auto num:nums) {
            if (count == 0) res = num;
            count += (res == num) ? 1:-1;
        }

        return res;
    }
};