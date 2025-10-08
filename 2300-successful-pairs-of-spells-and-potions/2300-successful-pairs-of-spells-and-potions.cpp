class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> result;

        for (long long spell : spells) {
            long long required = (success + spell - 1) / spell; // ceil(success / spell)
            int idx = lower_bound(potions.begin(), potions.end(), required) - potions.begin();
            result.push_back(n - idx);
        }

        return result;
    }
};