class Solution {
public:
    bool isUgly(int n) {
        if (n<=0) return false; //numbers <= 0 are not ugly
        while (n%2 == 0) { //divide by 2 as long as it's divisible by 2
            n/=2;
        }
        while (n%3 == 0) { //divide by 3 as long as it's divisible by 3
            n/=3;
        }
        while (n%5 == 0) { //divide by 5 as long as it's divisible by 5
            n/=5;
        }

        return (n==1); //if n is reduced to 1, it has no other prime factors other than 2,3,5
    }
};