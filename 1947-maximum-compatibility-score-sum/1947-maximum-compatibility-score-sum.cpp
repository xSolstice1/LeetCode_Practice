class Solution {
public:
    int m, n;
    vector<vector<int>> score;
    unordered_map<int,int> memo;
    int dfs(int student, int mask) {
        if (student == m) return 0; //base case, all assigned
        if (memo.count((student<<m) | mask)) return memo[(student<<m) | mask]; //memo caching

        int best = 0;
        for (int j = 0; j < m; j++) {
            if (!(mask & (1<<j))) { //skip mentor
                best = max(best, score[student][j] + dfs(student+1, mask | (1<<j)));
            }
        }
        return memo[(student<<m) | mask] = best;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = students.size();
        n = students[0].size();

        score.assign(m, vector<int>(m, 0));
        //precompute compatibility
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                int cnt = 0;
                for (int k=0; k<n; k++) {
                    if (students[i][k] == mentors[j][k]) cnt++;
                }
                score[i][j] = cnt;
            }
        }

        return dfs(0, 0);
    }
};