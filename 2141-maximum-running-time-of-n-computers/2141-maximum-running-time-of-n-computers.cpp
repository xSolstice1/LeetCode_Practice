class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;

        for (int x:batteries) total+=x;

        sort(batteries.begin(), batteries.end());

        for (int i=batteries.size()-1; i>=0; i--) {
            if (batteries[i]>total/n) {
                total-=batteries[i];
                n--;
            } else {
                break;
            }
        }

        return total/n;
    }
};