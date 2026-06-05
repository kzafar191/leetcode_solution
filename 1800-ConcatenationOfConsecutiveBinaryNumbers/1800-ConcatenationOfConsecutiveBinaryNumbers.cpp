// Last updated: 5/6/2026, 5:08:47 pm
class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        long long MOD = 1000000007;
        
        for (int i = 1; i <= n; ++i) {
            int length = log2(i) + 1;
            ans = ((ans << length) + i) % MOD;
        }
        
        return ans;
    }
};