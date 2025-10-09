class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> time(n, 0);

        for (int x : mana) {
            // Forward pass: compute finish times
            time[0] += 1LL * skill[0] * x;
            for (int i = 1; i < n; i++) {
                long long start = max(time[i], time[i - 1]);
                time[i] = start + 1LL * skill[i] * x;
            }

            // Backward pass: compute new start times
            for (int i = n - 2; i >= 0; i--) {
                time[i] = time[i + 1] - 1LL * skill[i + 1] * x;
            }
        }

        return time[n - 1];
    }
};