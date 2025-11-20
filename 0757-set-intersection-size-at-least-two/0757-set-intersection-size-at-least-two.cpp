class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        int s1 = INT_MIN, s2 = INT_MIN;
        for (auto &it : intervals) {
            int l = it[0], r = it[1];
            if (l > s2) {
                ans += 2;
                s1 = r - 1;
                s2 = r;
            } else if (l > s1) {
                ans += 1;
                s1 = s2;
                s2 = r;
            }
        }
        return ans;
    }
};