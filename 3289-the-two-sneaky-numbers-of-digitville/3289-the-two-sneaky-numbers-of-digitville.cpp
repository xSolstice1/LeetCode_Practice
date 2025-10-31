class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n < 2) return res;
        int m = n - 2;

        for (int &val : nums) {
            int idx = val % m; 
            if (nums[idx] >= m) {
                res.push_back(idx);
                if (res.size() == 2) break;
            } else {
                nums[idx] += m; 
            }
        }

        return res;
    }
};