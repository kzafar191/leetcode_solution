// Last updated: 5/6/2026, 5:10:36 pm
class Solution {
public:

    int recurse(vector<vector<int>>& dp,vector<vector<int>>& grid,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int up=INT_MAX,lf=INT_MAX;
        if(i>0) up= recurse(dp,grid,i-1,j);
        if(j>0) lf= recurse(dp,grid,i,j-1);
        dp[i][j] = min(up,lf)+grid[i][j];
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        for(int i=0;i<grid.size();i++){
            dp.push_back({});
            for(int j=0;j<grid[0].size();++j){
                dp[dp.size()-1].push_back(-1);
            }
        }
        dp[0][0]=grid[0][0];
        recurse(dp,grid,grid.size()-1,grid[0].size()-1);
        return dp[grid.size()-1][grid[0].size()-1];
    }
};