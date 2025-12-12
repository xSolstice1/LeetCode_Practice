class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        struct E { int t, type, id; string msg; };
        vector<E> es;

        es.reserve(events.size());
        for (auto &e : events) {
            int t = stoi(e[1]);
            if (e[0] == "OFFLINE") {
                es.push_back({t, 0, stoi(e[2]), ""});
            } else {
                es.push_back({t, 1, -1, e[2]});
            }
        }

        sort(es.begin(), es.end(), [](auto &a, auto &b){
            if (a.t != b.t) return a.t < b.t;
            return a.type < b.type;
        });

        vector<int> nextOnline(numberOfUsers, 0), ans(numberOfUsers, 0);

        for (auto &e : es) {
            int t = e.t;
            for (int i = 0; i < numberOfUsers; i++)
                if (nextOnline[i] <= t) nextOnline[i] = 0;

            if (e.type == 0) {
                nextOnline[e.id] = t + 60;
                continue;
            }

            string &msg = e.msg;
            if (msg == "ALL") {
                for (int i = 0; i < numberOfUsers; i++) ans[i]++;
            } else if (msg == "HERE") {
                for (int i = 0; i < numberOfUsers; i++)
                    if (nextOnline[i] == 0) ans[i]++;
            } else {
                int v = 0;
                for (int i = 0; i <= msg.size(); i++) {
                    if (i < msg.size() && isdigit(msg[i])) {
                        v = v * 10 + (msg[i] - '0');
                    } else if (i == msg.size() || msg[i] == ' ') {
                        ans[v]++;
                        v = 0;
                    }
                }
            }
        }

        return ans;
    }
};
