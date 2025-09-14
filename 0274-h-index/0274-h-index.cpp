class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n+1,0); //frequency of score

        //count frequency of scores
        for (int c:citations) {
            if (c>=n) freq[n]++;
            else freq[c]++;
        }

        int total = 0;

        for (int score=n; score>=0; score--) {
            total += freq[score]; //add frequency of score to total

            if (total >= score) return score; //when the total count is >= score, return score
        }

        return 0;
    }
};