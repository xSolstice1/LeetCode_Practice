class Solution {
public:
    int divide(int dividend, int divisor) {
        //edge case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        //XOR - true if same signage, false if different
        bool negative = (dividend < 0) ^ (divisor < 0);

        //convert dividends and divisor to neg
        long long a = dividend, b = divisor;
        a = (a > 0) ? -(long long)a : a;
        b = (b > 0) ? -(long long)b : b;

        int result = 0;
        while (a <= b) {
            long long temp = b, multiple = 1;
            while (a <= (temp << 1) && (temp << 1) < 0) {
                temp <<= 1; //left shift temp 1 bit
                multiple <<= 1; //left shift multiple 1 bit
            }
            a -= temp;
            result += multiple;
        }

        return negative ? -(long long)result : result;
    }
};
