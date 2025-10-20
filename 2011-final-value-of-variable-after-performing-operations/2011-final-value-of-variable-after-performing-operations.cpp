class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;

        for (string s:operations) {
            if (s.find('-') != string::npos) {
                res--;
            } else {
                res++;
            }
        }

        return res;
    }
};