class Solution {
public:
    //fibonacci ways(n)=ways(n−1)+ways(n−2)
    int climbStairs(int n) {
        int a=1,b=1;
        
        for (int i=0; i<n-1; i++) {
            int c=a; //temp to store a
            a+=b; //fib step (a+b)
            b=c; //b = previous a
        }

        return a; //a = ways(n)
    }
};