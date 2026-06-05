// Last updated: 5/6/2026, 5:05:26 pm
class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (__int128)res * base % mod;
            base = (__int128)base * base % mod;
            exp /= 2;
        }
        return res;
    }
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        int mod = 1e9 + 7;
        long long ans = 0; 
        vector<vector<int>> pair;
        long long tot = 0;
        
        for(int i = 0; i < n; ++i){
            tot += (nums1[i] + nums0[i]);
        }
        
        for(int i = 0; i < n; ++i){
            if(nums0[i] == 0){
                if (nums1[i] > 0) {
                    long long val = (power(2, tot, mod) - power(2, tot - nums1[i], mod) + mod) % mod;
                    ans = (ans + val) % mod;
                    
                    tot -= nums1[i];
                    nums1[i] = 0; 
                }
            }
            int zer = nums0[i];
            int one = nums1[i];
            pair.push_back({one, -zer});
        }
        
        sort(pair.begin(), pair.end());
        n = pair.size();
        
        for(int i = n - 1; i >= 0; --i){
            int one = pair[i][0];
            int zero = -pair[i][1];
            
            if (one > 0) {
                long long val = (power(2, tot, mod) - power(2, tot - one, mod) + mod) % mod;
                ans = (ans + val) % mod;
                
                tot -= one;
            }
            tot -= zero;
        }
        
        return ans % mod;
    }
};