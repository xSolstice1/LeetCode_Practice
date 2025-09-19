class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> numSet;
        numSet.insert(1);

        long curr = 1;
        for (int i=0; i<n; i++) {
            curr=*numSet.begin();
            numSet.erase(numSet.begin());

            numSet.insert(curr*2);
            numSet.insert(curr*3);
            numSet.insert(curr*5);
        }

        return curr;
    }
};