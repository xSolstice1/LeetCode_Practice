class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = i + 1;

        vector<int> factors(n + 1, 1);
        for (int i = 1; i <= n; ++i) factors[i] = factors[i - 1] * i;

        k -= 1; //convert to 0-based index
        string ans;
        for (int len = n; len >= 1; --len) {
            int blockSize = factors[len - 1];
            int index = k / blockSize;
            k = k % blockSize;

            ans.push_back(char('0' + nums[index]));
            nums.erase(nums.begin() + index);
        }
        return ans;
    }
};