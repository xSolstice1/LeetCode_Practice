class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = INT_MIN; //initalize min price and max profit

        for (int x:prices) {
            minPrice = min(minPrice,x);
            maxProfit = max(maxProfit, x-minPrice);
        }

        return maxProfit;
    }
};