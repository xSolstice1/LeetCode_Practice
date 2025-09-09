class Solution {
public:
    bool isValid(string& s) {
        // if (s.empty()) return false;
        if (s.size() > 1 && s[0] == '0') return false; //leading 0
        int sVal = stoi(s);

        return sVal >= 0 && sVal <= 255; //verify part of IP to be 0-255
    }
    void backtrack(string s, string curr, vector<string>& res, int part, int start) {
        if (part == 4 && start == s.size()) {
            res.push_back(curr);
            return;
        }
        if (part == 4) return; //invalid

        for (int i=1; i<=3; i++) { //at most 3 numbers per ip part
            if (start+i > s.size()) break; //invalid out of bounds
            string ipPart = s.substr(start,i);
            if (isValid(ipPart)) {
                backtrack(s,curr+ipPart+(part<3 ? ".":""),res,part+1,start+i);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string curr;
        vector<string> res;

        backtrack(s,curr,res,0,0);

        return res;
    }
};