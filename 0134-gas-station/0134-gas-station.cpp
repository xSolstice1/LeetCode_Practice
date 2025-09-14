class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, totalGas = 0, startPos = 0;

        for (int i=0; i<gas.size(); i++) {
            tank += gas[i]-cost[i]; //add gas at station i and cost to get to station i to tank
            totalGas += gas[i]-cost[i]; //add gas at station i and cost to get to station i to totalGas 

            if (tank<0) { //reset if no more gas
                startPos = i+1;
                tank = 0;
            }
        }

        return totalGas >= 0 ? startPos : -1; //check if totalGas at the end of loop is positive
    }
};