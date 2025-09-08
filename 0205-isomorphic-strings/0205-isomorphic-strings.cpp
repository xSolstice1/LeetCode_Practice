class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp_s, mp_t;

        for (int i=0; i<s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            if (mp_s.count(c1) && mp_s[c1] != c2) { //mapping mismatch?
                return false;
            }
            if (mp_t.count(c2) && mp_t[c2] != c1) { //mapping mismatch?
                return false;
            }

            mp_s[c1] = c2; //map s char to t char
            mp_t[c2] = c1; //map t char to s char
        }

        return true;      
    }
};