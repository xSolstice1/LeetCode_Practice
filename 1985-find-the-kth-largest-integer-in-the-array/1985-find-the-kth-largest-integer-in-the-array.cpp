class Solution {
public:
    struct strCompare {
        bool operator()(const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a>b;
            }
            return a.size()>b.size();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,strCompare> pq;

        for (string s:nums) {
            pq.push(s);
            if (pq.size()>k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};