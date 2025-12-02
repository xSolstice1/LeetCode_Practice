class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;

        for (auto v:points) mp[v[1]]++;

        const int MOD = 1e9+7;
        long long sum = 0,res = 0;

        for (auto& [_,x]:mp) {
            long long calc = (long long) x*(x-1)/2;
            res+=sum*calc;
            sum+=calc;
        }

        return res%MOD;
    }
};