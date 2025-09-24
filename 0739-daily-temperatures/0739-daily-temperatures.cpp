class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> indSt;
        vector<int> res(n,0);

        for (int i=0; i<n; i++) {
            while (!indSt.empty() && temperatures[i] > temperatures[indSt.top()]) {
                int temp = indSt.top();
                indSt.pop();
                res[temp] = i-temp; //calculate distance to next warmer day
            }
            indSt.push(i);
        }

        return res;
    }
};