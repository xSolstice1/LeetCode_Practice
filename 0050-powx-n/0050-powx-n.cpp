class Solution {
public:
    double myPow(double x, int n) {
        long long nLL = n; //avoid overflow, convert to long long
        if (nLL < 0) {
            x = 1 / x;
            nLL = -nLL;
        }

        double result = 1.0;
        while (nLL > 0) {
            if (nLL % 2 == 1) result *= x;
            x *= x;
            nLL /= 2;
        }
        return result;
    }
};
