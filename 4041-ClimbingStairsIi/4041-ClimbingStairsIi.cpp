// Last updated: 5/6/2026, 5:07:28 pm
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1,1e15);
        dp[0] = 0;
        for(int i=0;i<n;++i){
            if(dp[i+1]>costs[i]+1+dp[i]) dp[i+1] = costs[i]+1+dp[i];
            if(i+2<=n && dp[i+2]>costs[i+1]+4+dp[i]) dp[i+2] = costs[i+1]+4+dp[i];
            if(i+3<=n && dp[i+3]>costs[i+2]+9+dp[i]) dp[i+3] = costs[i+2]+9+dp[i];
        }
        return dp[n];
    }
};