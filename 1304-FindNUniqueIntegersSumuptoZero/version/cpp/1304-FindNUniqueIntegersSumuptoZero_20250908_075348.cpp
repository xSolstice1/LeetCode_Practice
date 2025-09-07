// Last updated: 9/8/2025, 7:53:48 AM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        
        if (n%2 != 0) {
            res.push_back(0);
        }

        for (int i=1; i<=n/2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }

        return res;
    }
};