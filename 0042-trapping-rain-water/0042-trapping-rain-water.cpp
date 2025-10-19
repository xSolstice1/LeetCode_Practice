class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, res=0, r=height.size()-1, l=0, maxL=INT_MIN, maxR=INT_MIN;

        while (l<r) {
            maxL=max(height[l],maxL);
            maxR=max(height[r],maxR);

            ans += maxL<maxR?height[l++]-maxL:height[r--]-maxR;
        }

        return -ans;
    }
};