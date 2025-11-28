class Solution {
public:
    int n, k;
    vector<vector<int>> g;
    vector<int> vals;
    int ans = 0;

    int dfs(int u, int p) {
        long long sum = vals[u];
        for (int v : g[u]) {
            if (v == p) continue;
            long long s = dfs(v, u);
            if (s % k == 0) ans++;
            else sum += s;
        }
        return sum % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->n = n;
        this->k = k;
        vals = values;
        g.assign(n, {});
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return (dfs(0, -1) % k == 0) ? ans + 1 : ans;
    }
};
