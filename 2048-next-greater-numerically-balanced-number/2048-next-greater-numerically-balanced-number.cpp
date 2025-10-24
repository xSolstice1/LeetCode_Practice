static vector<int> Bal;
static int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

class Solution {
public:
    // Generate all permutations of a given set of digits
    static void permDigits(vector<int>& digit) {
        int dz = digit.size();
        if (dz == 1) {  // Only one digit
            int x = 0, d = digit[0];
            for (int i = 0; i < d; i++) 
                x = 10 * x + d;
            Bal.push_back(x);
            return;
        }

        // Multiple digits: generate all permutations
        string s = "";
        for (int d : digit) 
            s.insert(s.end(), d, '0' + d);  // repeat each digit d times

        do {
            int x = stoi(s);
            if (x <= 1224444)  // only keep reasonable numbers
                Bal.push_back(x);
        } while (next_permutation(s.begin(), s.end()));
    }

    // Generate all numerically balanced numbers
    static void genBalanced() {
        if (!Bal.empty()) return;  // Already generated

        for (unsigned mask = 1; mask < (1u << 6); mask++) {
            int len = 0;
            vector<int> digit;
            for (int d = 0; d < 6; d++) {
                if (mask & (1 << d)) {
                    len += d + 1;
                    if (len > 7) break;  // skip too long numbers
                    digit.push_back(d + 1);
                }
            }
            if (len <= 7)
                permDigits(digit);
        }

        sort(Bal.begin(), Bal.end());
    }

    // Return the next numerically balanced number > n
    static int nextBeautifulNumber(int n) {
        genBalanced();
        return *upper_bound(Bal.begin(), Bal.end(), n);
    }
};
