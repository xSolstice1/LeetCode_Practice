class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int result = 0;

        for (int z = 0; z + z * z <= n; ++z) {
            int left = 0, lastBad = -1;
            vector<int> freq(2, 0);

            for (int right = 0; right < n; ++right) {
                freq[s[right] - '0']++;

                while (left < right) {
                    if (s[left] == '0' && freq[0] > z) {
                        freq[0]--;
                        lastBad = left;
                        left++;
                    } else if (s[left] == '1' && freq[1] - 1 >= z * z) {
                        freq[1]--;
                        left++;
                    } else {
                        break;
                    }
                }

                if (freq[0] == z && freq[1] >= z * z)
                    result += left - lastBad;
            }
        }

        return result;
    }
};
