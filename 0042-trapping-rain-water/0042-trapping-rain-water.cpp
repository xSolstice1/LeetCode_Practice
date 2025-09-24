class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1, maxL=INT_MIN, maxR=INT_MIN, ans=0;

        while (l<r) {
            maxL = max(maxL,height[l]);
            maxR = max(maxR,height[r]);

            ans += maxL < maxR ? maxL - height[l++] : maxR - height[r--];
        }

        return ans;
    }
};