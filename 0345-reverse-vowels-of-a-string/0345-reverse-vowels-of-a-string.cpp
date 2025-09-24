class Solution {
public:
    string reverseVowels(string s) {
        // int i = 0, j = s.length() - 1;
        // while (i < j) {
        //     if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
        //         s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
        //         i++;
        //         continue;
        //     }
        //     if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' &&
        //         s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U') {
        //         j--;
        //         continue;
        //     }
        //     swap(s[i], s[j]);
        //     i++;
        //     j--;
        // }
        // return s;
        
        //string lookup
        // string vowels = "aeiouAEIOU";
        // int i=0, j=s.length()-1;

        // while (i<j) {
        //     while (i<j && vowels.find(s[i]) == string::npos) {
        //         i++;
        //     }
        //     while (i<j && vowels.find(s[j]) == string::npos) {
        //         j--;
        //     }
        //     swap(s[i],s[j]);
        //     i++;
        //     j--;
        // }

        // return s;

        //set lookup
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (i < j && vowels.find(s[i]) == vowels.end()) {
                i++;
            }
            while (i < j && vowels.find(s[j]) == vowels.end()) {
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};