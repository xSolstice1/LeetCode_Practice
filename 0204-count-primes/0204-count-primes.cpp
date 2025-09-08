class Solution {
public:
    //Sieve of Eratosthenes
    int countPrimes(int n) {
        if (n<=2) return false;

        vector<bool> isPrime(n,true); //boolean vector, initialized to size n and all true
        isPrime[0] = isPrime[1] = false; //0 and 1 are not prime numbers

        for (int i=2; i*i<n; i++) { //loop till sqrt(n)
            for (int j=i*i; j<n; j+=i) {
                isPrime[j] = false; //multiplies of i are non-prime
            }
        }

        return count(isPrime.begin(),isPrime.end(),true); //count final number of primes
    }
};