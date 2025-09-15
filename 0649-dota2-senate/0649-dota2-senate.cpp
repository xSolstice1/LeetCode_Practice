class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> direQ, radiantQ;

        //populate queues
        for (int i=0; i<senate.size(); i++) {
            if (senate[i]=='R') {
                radiantQ.push(i);
            } else {
                direQ.push(i);
            }
        }

        while (!radiantQ.empty() && !direQ.empty()) {
            int radiantIndex = radiantQ.front(); radiantQ.pop();
            int direIndex = direQ.front(); direQ.pop();

            if (radiantIndex < direIndex) {
                radiantQ.push(radiantIndex+senate.size());
            } else {
                direQ.push(direIndex+senate.size());
            }
        }

        return direQ.empty() ? "Radiant":"Dire";
    }
};