// Last updated: 5/6/2026, 5:06:12 pm
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> dp(n, vector<bool> (1024,false));
        dp[0][grid[0][0]] = true;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!i && !j) continue;
                vector<bool> ndp (1024,false);
                for(int k =0;k<1024;++k){
                    if(i&&dp[j][k] || j&&dp[j-1][k]){
                        ndp[k^grid[i][j]] = true;
                        
                    }
                }
                dp[j] = ndp;
            }
        }
        for(int k=0;k<1024;++k){
            if(dp[n-1][k]) return k;
        }

        return 0;
    }
};