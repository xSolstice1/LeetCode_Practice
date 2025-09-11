class Solution {
public:
    void backtrack(vector<int> toppingCosts, int target, int index, int currCost, int& closest) {
        if (abs(currCost - target) < abs(closest - target) || 
        (abs(currCost - target) == abs(closest - target) && currCost < closest)) {
        closest = currCost;
        }
        if (index == toppingCosts.size()) return; //reached the end

        backtrack(toppingCosts,target,index+1,currCost,closest);
        backtrack(toppingCosts,target,index+1,currCost+toppingCosts[index],closest);
        backtrack(toppingCosts,target,index+1,currCost+2*toppingCosts[index],closest);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int closest = baseCosts[0];

        for (int baseCost:baseCosts) {
            backtrack(toppingCosts,target,0,baseCost,closest);
        }

        return closest;
    }
};