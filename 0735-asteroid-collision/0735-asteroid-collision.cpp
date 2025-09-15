class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int x:asteroids) {
            bool d = false;

            while (!res.empty() && res.back() > 0 && x < 0) {
                if (abs(res.back()) < abs(x)) {
                    res.pop_back(); //right exploded
                    continue; //check
                } else if (abs(res.back()) == abs(x)) {
                    res.pop_back(); //both exploded
                    d = true;
                    break;
                } else {
                    d = true; //left exploded
                    break;
                }
            }

            if (!d) res.push_back(x);
        }

        return res;
    }
};