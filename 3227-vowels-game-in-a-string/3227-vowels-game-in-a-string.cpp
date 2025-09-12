class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};
        for (char c:s) {
            if (vowelSet.count(c)) {
                return true;
            }
        }

        return false;
    }
};