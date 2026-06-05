// Last updated: 5/6/2026, 5:09:12 pm
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,10000));

        dp[0] = matrix[0];

        for(int i=1;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                for(int k=j-1;k<=j+1;++k){
                    if(k==-1 || k==n) continue;
                    if(dp[i-1][k]+matrix[i][j]<dp[i][j]) dp[i][j] = dp[i-1][k]+matrix[i][j];
                }
            }
        }

        int mn = 10000;
        for(int i=0;i<n;++i) mn = min(dp[n-1][i],mn);
        return mn;
    }
};