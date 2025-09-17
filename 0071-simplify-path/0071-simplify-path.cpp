class Solution {
public:
    string simplifyPath(string path) {
        vector<string> simplifiedPath;
        stringstream ss(path);
        string w = "";

        while (getline(ss,w,'/')) {
            if (w=="" || w==".") {
                continue;
            }
            if (w=="..") {
                if (!simplifiedPath.empty()) {
                    simplifiedPath.pop_back();
                }
            } else {
                simplifiedPath.push_back(w);
            }
        }

        w.clear();
        for (string s:simplifiedPath) {
            w += "/";
            w += s;
        }

        return w.empty() ? "/" : w;
    }
};