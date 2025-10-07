class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> full;  // lake -> last day it was filled
        set<int> dry_days;             // sorted indices of dry days
        vector<int> ans(n, 1);         // default 1 for dry days; -1 for rainy days

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];

            if (lake == 0) {
                dry_days.insert(i);   // store dry day index
            } 
            else {
                ans[i] = -1; // raining day output
                if (full.count(lake)) {
                    // find a dry day after the lake was last filled
                    auto it = dry_days.upper_bound(full[lake]);
                    if (it == dry_days.end()) {
                        return {}; // no dry day available → flood
                    }
                    int dry_day = *it;
                    ans[dry_day] = lake; // dry this lake on that day
                    dry_days.erase(it);
                }
                full[lake] = i; // mark current day as filled
            }
        }
        return ans;
    }
};