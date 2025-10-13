class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prev = "";  // store normalized form of previous word

        for (auto& word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  // normalize

            if (sortedWord != prev) {  // only keep if not an anagram of previous
                result.push_back(word);
                prev = sortedWord;
            }
        }

        return result;
    }
};
