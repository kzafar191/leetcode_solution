// Last updated: 5/6/2026, 5:08:05 pm
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = 0;
        dp[0][0][2] = 0;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(j!=0){
                    dp[i][j][0] = dp[i][j-1][0]+coins[i][j];
                    dp[i][j][1] = max(dp[i][j-1][0],dp[i][j-1][1]+coins[i][j]);
                    dp[i][j][2] = max(dp[i][j-1][1],dp[i][j-1][2]+coins[i][j]);
                }
                if(i!=0){
                    int a = dp[i-1][j][0]+coins[i][j];
                    int b = max(dp[i-1][j][0],dp[i-1][j][1]+coins[i][j]);
                    int c = max(dp[i-1][j][1],dp[i-1][j][2]+coins[i][j]);

                    dp[i][j][0] = max(a,dp[i][j][0]);
                    dp[i][j][1] = max(b,dp[i][j][1]);
                    dp[i][j][2] = max(c,dp[i][j][2]);
                }
            }
        }

        int ans = max(dp[m-1][n-1][0],dp[m-1][n-1][1]);
        ans = max(ans, dp[m-1][n-1][2]);
        return ans;
    }
};