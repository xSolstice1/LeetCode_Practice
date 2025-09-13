class Solution {
public:
    int maxFreqSum(string s) {
        int maxV = 0, maxC = 0;

        unordered_map<char,int> mpV, mpC;
        unordered_set<char> setV = {'a','e','i','o','u'};

        for (char c:s) {
            if (setV.count(c)) {
                mpV[c]++;
            } else {
                mpC[c]++;
            }
        }

        for (auto itr:mpV) {
            maxV = max(maxV,itr.second);
        }
        for (auto itr:mpC) {
            maxC = max(maxC,itr.second);
        }

        return maxV+maxC;
    }
};