class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, left = 0, right = height.size()-1, maxLeft = INT_MIN, maxRight = INT_MIN;

        while (left < right) {
            maxLeft = max(height[left],maxLeft);
            maxRight = max(height[right],maxRight);

            ans += maxLeft < maxRight ? maxLeft - height[left++] : maxRight - height[right--];
        }

        return ans;
    }
};