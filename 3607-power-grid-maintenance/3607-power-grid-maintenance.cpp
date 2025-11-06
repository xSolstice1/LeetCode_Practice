class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1), sz(c + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
        for (auto& e : connections) unite(e[0], e[1]);
        unordered_map<int, set<int>> online;
        for (int i = 1; i <= c; i++) online[find(i)].insert(i);
        vector<int> ans;
        vector<bool> isOnline(c + 1, true);
        for (auto& q : queries) {
            int t = q[0], x = q[1], r = find(x);
            if (t == 1) {
                if (isOnline[x]) ans.push_back(x);
                else ans.push_back(online[r].empty() ? -1 : *online[r].begin());
            } else {
                if (isOnline[x]) {
                    isOnline[x] = false;
                    online[r].erase(x);
                }
            }
        }
        return ans;
    }
};
