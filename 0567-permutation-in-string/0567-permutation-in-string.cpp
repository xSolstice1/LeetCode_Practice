class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> count(26, 0);
        for (char c : s1) count[c - 'a']++;

        int matches = 0;
        for (int i = 0; i < 26; i++)
            if (count[i] == 0) matches++;

        for (int i = 0; i < m; i++) {
            // Add the new character from s2
            int add = s2[i] - 'a';
            count[add]--;
            if (count[add] == 0) matches++;
            else if (count[add] == -1) matches--;

            // Remove the leftmost character when window > n
            if (i >= n) {
                int remove = s2[i - n] - 'a';
                count[remove]++;
                if (count[remove] == 0) matches++;
                else if (count[remove] == 1) matches--;
            }

            if (matches == 26) return true;
        }

        return false;
    }
};
