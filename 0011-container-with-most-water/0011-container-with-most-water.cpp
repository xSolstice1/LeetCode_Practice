class Solution {
public:
    //two pointers approach
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans = 0;

        while (l<r) {
            int temp = (r-l) * min(height[l],height[r]); //calculate area
            ans = max(temp,ans); //get max area

            if (height[l] < height[r]) { //move left pointer +1 if left height < right height
                l++;
            }
            else { //else shift right pointer -1
                r--;
            }
        }

        return ans;
    }
};