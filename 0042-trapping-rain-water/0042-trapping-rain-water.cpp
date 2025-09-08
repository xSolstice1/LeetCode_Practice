class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int maxLeft = INT_MIN; //max height to left
        int maxRight = INT_MIN; //max height to right
        int left = 0; //left pointer
        int right = height.size()-1; //right pointer

        while (left<right) {
            //update max left/right heights
            maxLeft = max(height[left],maxLeft);
            maxRight = max(height[right],maxRight);

            //update answer, check if left or right pointer is the limiting wall, move the pointer accordingly
            ans += maxLeft<maxRight ? maxLeft-height[left++] : maxRight-height[right--];
        }

        return ans;
    }
};