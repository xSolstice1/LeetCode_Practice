class Solution {
public:
    int numSub(string s) {
        int count = 0, res = 0, mod = 1e9+7;

        for (char c:s) {
            if (c=='1') {
                count++;
            } else {
                count=0;
            }
            res = (res+count) % mod;
        }

        return res;
    }
};