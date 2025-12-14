class Solution {
public:
    int numberOfWays(string corridor) {
        int MOD = 1e9+7, seats=0, parts=0;
        long ways=1;

        for (char c:corridor) {
            if (c=='S') {
                seats++;
            }
            if (seats==2) {
                parts++;
            }
            if (seats>2) {
                ways=(ways*parts)%MOD;
                parts=0;
                seats=1;
            }
        }

        if (seats!=2) {
            return 0;
        }

        return (int)ways;
    }
};