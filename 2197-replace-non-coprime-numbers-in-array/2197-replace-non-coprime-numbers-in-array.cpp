class Solution {
public:
    int lcm(int a, int b) {
        return a/gcd(a,b)*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> numStack;

        for (int x:nums) {
            int curr = x;
            while (numStack.size()) {
                int greatestCommonDiv = gcd(numStack.back(),curr);
                if (greatestCommonDiv == 1) break;
                curr = lcm(numStack.back(), curr);
                numStack.pop_back();
            }
            numStack.push_back(curr);
        }

        return numStack;
    }
};