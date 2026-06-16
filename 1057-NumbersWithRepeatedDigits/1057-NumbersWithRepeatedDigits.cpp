// Last updated: 16/6/2026, 2:01:41 pm
class Solution {
    int dp[11][2][2][1024];
    string str;

    long long solve(int i,int tight,int zero,int mask){
        if(i == str.size()) return 1;
        if(dp[i][tight][zero][mask] != -1) return dp[i][tight][zero][mask];
        long long cnt = 0;
        int upper_bound = tight ? (str[i] - '0') : 9;
        for(int d = 0; d <= upper_bound; d++){
            if(mask & (1 << d)) continue;
            if(zero && d == 0) {
                cnt += solve(i + 1, false, true, 0);
            } else {
                cnt += solve(i + 1, tight && (d == upper_bound), false, mask | (1 << d));
            }
        }   
        return dp[i][tight][zero][mask] = cnt;
    }
public:


    int numDupDigitsAtMostN(int n) {
        memset(dp,-1,sizeof(dp));
        str = to_string(n);
        return n - (solve(0,true,true,0)-1);
    }
};