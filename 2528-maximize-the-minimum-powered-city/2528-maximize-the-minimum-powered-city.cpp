class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + stations[i];
        vector<long long> power(n);
        for (int i = 0; i < n; i++) {
            int l = max(0, i - r), rr = min(n - 1, i + r);
            power[i] = pref[rr + 1] - pref[l];
        }
        auto can = [&](long long x) {
            long long added = 0, cur = 0;
            vector<long long> diff(n, 0);
            for (int i = 0; i < n; i++) {
                if (i > 0) cur += diff[i];
                long long total = power[i] + cur;
                if (total < x) {
                    long long need = x - total;
                    added += need;
                    if (added > k) return false;
                    cur += need;
                    if (i + 2 * r + 1 < n) diff[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };
        long long lo = 0, hi = 1e18, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (can(mid)) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }
};
