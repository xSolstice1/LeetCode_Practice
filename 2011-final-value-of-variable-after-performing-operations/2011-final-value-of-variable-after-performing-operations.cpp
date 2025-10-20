class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        // int res=0;

        // for (string s:operations) {
        //     if (s.find('-') != string::npos) {
        //         res--;
        //     } else {
        //         res++;
        //     }
        // }

        // return res;

        int res=0;

        for (string& s:operations) {
            res += s[1] == '-' ? -1:1;
        }

        return res;
    }
};