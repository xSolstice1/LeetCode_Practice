class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word = "";
        vector<string> words;

        while (ss>>word) {
            words.push_back(word);
        }

        int res = words.size();

        for (string& s:words) {
            for (char c:brokenLetters) {
                if (s.find(c) != string::npos) {
                    res--;
                    break;
                }
            }
        }

        return res;
    }
};