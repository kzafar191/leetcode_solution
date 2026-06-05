// Last updated: 5/6/2026, 5:05:48 pm
class Solution {
public:
    long long power(long long x, int y, int p)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0) 
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}
    long long ncr(long long n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
    
    int countVisiblePeople(int n, int pos, int k) {
        long long num = n;
        int r = k;
        int mod = 1e9 +7;
        return (2*(int)ncr(n-1,r,mod))%mod;
    }
};