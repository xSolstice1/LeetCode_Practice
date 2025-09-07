// Last updated: 07/09/2025, 23:46:31
class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size()<2) return "";

        unordered_set<char> strSet(s.begin(),s.end());

        for (int i=0; i<s.size(); i++) {
            char c = s[i];

            if (strSet.count(toupper(c)) && strSet.count(tolower(c))) {
                continue;
            }

            string l = longestNiceSubstring(s.substr(0,i));
            string r = longestNiceSubstring(s.substr(i+1));

            return l.size()>=r.size() ? l:r;
        }

        return s;
    }
};