class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int,int> count;

        for (auto x:answers) {
            count[x]++;
        }

        for (auto &[ans,freq]:count) {
            int size = ans+1;
            int groups = (freq+size-1)/size;
            res += groups * size;
        }

        return res;
    }
};