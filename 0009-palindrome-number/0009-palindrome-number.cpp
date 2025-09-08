class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x); //convert x to string
        int r = s.size()-1; //2 pointers

        for (int l=0; l<s.size(); l++) {
            if (s[l]!=s[r--]) {
                return false;
            }
        }

        return true;
    }
};