class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> positions;
        for (int i = 0; i < s.size(); i++) {
            positions[s[i]].push_back(i);
        }

        int total = 0;
        for (auto &entry : positions) {
            const vector<int> &posList = entry.second;
            int first = posList[0];
            int last = posList[posList.size() - 1];

            if (last - first <= 1) continue;

            unordered_set<char> middleChars;
            for (int i = first + 1; i < last; i++) {
                middleChars.insert(s[i]);
            }

            total += middleChars.size();
        }
        return total;
    }
};
