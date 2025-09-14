class Solution {
public:
    void removeVowel(string& s) {
        for (char& c:s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '.'; //change vowels to '.'
        }
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;

        for (string &word : wordlist) {
            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            //case insensitive first occur
            if (!caseMap.count(lower)) caseMap[lower] = word;

            //removeVowels
            string devow = lower;
            removeVowel(devow);
            if (!vowelMap.count(devow)) vowelMap[devow] = word;
        }

        vector<string> ans;
        for (string &query : queries) {
            if (exact.count(query)) {
                ans.push_back(query);
                continue;
            }

            string lower = query;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }

            string devow = lower;
            removeVowel(devow);
            if (vowelMap.count(devow)) {
                ans.push_back(vowelMap[devow]);
                continue;
            }

            ans.push_back("");  // no match
        }

        return ans;
    }
};