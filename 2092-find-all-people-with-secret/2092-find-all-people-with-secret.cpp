class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[b] = a;
        };
        
        unite(0, firstPerson);
        
        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            vector<int> touched;
            
            int j = i;
            while (j < meetings.size() && meetings[j][2] == t) {
                unite(meetings[j][0], meetings[j][1]);
                touched.push_back(meetings[j][0]);
                touched.push_back(meetings[j][1]);
                j++;
            }
            
            for (int p : touched) {
                if (find(p) != find(0)) {
                    parent[p] = p;
                }
            }
            
            i = j;
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0)) res.push_back(i);
        }
        return res;
    }
};
