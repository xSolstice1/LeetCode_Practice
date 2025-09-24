class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int ans = INT_MIN;

        while (l<r) {
            int area = (r-l) * min(height[r],height[l]);
            ans = max(ans,area);

            if (height[r]>height[l]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};