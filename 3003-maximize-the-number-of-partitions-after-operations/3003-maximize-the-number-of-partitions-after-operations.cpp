class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        if (k == 26) return 1; // no split possible

        // left[i] stores info for prefix ending at i-1
        vector<array<int,3>> left(n), right(n);
        
        // left scan
        {
            int num = 0, mask = 0, distinct = 0;
            for (int i = 0; i < n - 1; ++i) {
                int bit = 1 << (s[i] - 'a');
                if (!(mask & bit)) {
                    distinct++;
                    if (distinct > k) {
                        num++;
                        mask = bit;
                        distinct = 1;
                    } else mask |= bit;
                }
                left[i + 1] = {num, mask, distinct};
            }
        }

        // right scan
        {
            int num = 0, mask = 0, distinct = 0;
            for (int i = n - 1; i > 0; --i) {
                int bit = 1 << (s[i] - 'a');
                if (!(mask & bit)) {
                    distinct++;
                    if (distinct > k) {
                        num++;
                        mask = bit;
                        distinct = 1;
                    } else mask |= bit;
                }
                right[i - 1] = {num, mask, distinct};
            }
        }

        auto popcount = [](int x) {
            return __builtin_popcount(x);
        };

        int ans = 1; // at least one segment
        for (int i = 0; i < n; ++i) {
            int segments = left[i][0] + right[i][0] + 2;
            int combinedMask = left[i][1] | right[i][1];
            int distinct = popcount(combinedMask);

            // Case 1: both sides are saturated but we can still introduce a new char
            if (left[i][2] == k && right[i][2] == k && distinct < 26)
                segments++;
            // Case 2: combined set too small, one partition can merge
            else if (min(distinct + 1, 26) <= k)
                segments--;

            ans = max(ans, segments);
        }
        return ans;
    }
};