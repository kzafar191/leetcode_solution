// Last updated: 5/6/2026, 5:08:38 pm
class Solution {
public:
   const long long MOD = 1000000007; 
long long fastExp(long long x, long long n) {
    if (n == 0) return 1; // base case
    if (n == 1) return x % MOD;

    long long half = fastExp(x, n / 2);
    half = (half * half) % MOD;

    if (n & 1) return (half * (x % MOD)) % MOD;
    else return half;
}

    int countGoodNumbers(long long n) {
       long long sol1 = 5;
       sol1= fastExp(5, n/2+(n&1));
       long long sol2 = fastExp(4, n/2);
       return ((sol1%1000000007)*(sol2%1000000007))%1000000007;
    }
};