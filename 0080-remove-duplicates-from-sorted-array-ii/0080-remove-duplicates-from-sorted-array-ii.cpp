class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        //check for 2 or less numbers, if so, no duplicate, return vector size
        if (n <= 2) return n;
        
        //starting position
        int j = 2;

        //if nums[i] is not equal to nums[j-2], no duplicate of length > 2, shift index j forward
        for (int i=2; i<n; i++) {
            if (nums[i] != nums[j-2]) nums[j++] = nums[i];
        }

        return j;
    }
};