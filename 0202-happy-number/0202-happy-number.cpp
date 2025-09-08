class Solution {
private:
    //helper function to square digits of n
    int check(int n) {
        int sum = 0;
        while (n>0) {
            int remain = n%10;
            sum += remain*remain;
            n/=10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = check(n);
        while (fast != 1 && slow != fast) {
            slow = check(slow);
            fast = check(check(fast));
        }
        return fast == 1;
    }
};