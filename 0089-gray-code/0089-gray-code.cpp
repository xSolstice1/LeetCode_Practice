class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n; // bitwise shift
        vector<int> result;
        unordered_set<int> seen;
        result.push_back(0);
        seen.insert(0);

        backtrack(n, total, result, seen);
        return result;
    }

private:
    bool backtrack(int n, int total, vector<int>& result, unordered_set<int>& seen) {
        if (result.size() == total) {
            //check if first and last differ by 1 bit
            int first = result.front();
            int last = result.back();
            int x = first ^ last;
            return (x && !(x & (x - 1)));
        }

        int curr = result.back();
        for (int i = 0; i < n; i++) {
            int next = curr ^ (1 << i); //flip i-th bit
            if (!seen.count(next)) {
                result.push_back(next);
                seen.insert(next);

                if (backtrack(n, total, result, seen)) return true;

                //backtrack
                result.pop_back();
                seen.erase(next);
            }
        }
        return false;
    }
};