class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<int> dir = {0, 1, 0, -1, 0};
        int res = 0;

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];
            res = max(res, h);
            if (x == n-1 && y == n-1) return res;
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i+1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return res;
    }
};
