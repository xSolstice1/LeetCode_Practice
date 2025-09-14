class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; //normalize k
        vector<int> temp(n); //temp array

        for (int i=0; i<n; i++) {
            temp[(i+k)%n] = nums[i]; //rotate in-place
        }

        nums=temp;
    }
};