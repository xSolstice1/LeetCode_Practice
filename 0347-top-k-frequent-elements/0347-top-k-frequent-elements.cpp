class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int& x:nums) {
            freq[x]++;
        }

        priority_queue<pair<int,int>> pq;

        for (auto& itr:freq) {
            pq.push({itr.second,itr.first});
        }

        vector<int> res;

        while (k-- > 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};