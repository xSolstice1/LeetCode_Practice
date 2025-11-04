class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; i++) {
            unordered_map<int,int> freq;

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            vector<pair<int,int>> arr(freq.begin(), freq.end());

            sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            
            int sum = 0;
            int taken = 0;
            for (auto &[num, cnt] : arr) {
                if (taken == x) break;
                sum += num * cnt;
                taken++;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
