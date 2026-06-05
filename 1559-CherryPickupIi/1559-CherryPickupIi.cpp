// Last updated: 5/6/2026, 5:08:58 pm
class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        dp[0][m-1]=g[0][0]+g[0][m-1];
        for(int i=1;i<n;++i){
            vector<vector<int>> cur(m,vector<int>(m,-1));
            for(int j=0;j<m;++j){
                for(int k=0;k<m;++k){
                    int best=-1;
                    for(int x=j-1;x<=j+1;++x){
                        for(int y=k-1;y<=k+1;++y){
                            if(x>=0&&x<m&&y>=0&&y<m&&dp[x][y]!=-1)
                                best=max(best,dp[x][y]);
                        }
                    }
                    if(best!=-1)
                        cur[j][k]=best+g[i][j]+(j==k?0:g[i][k]);
                }
            }
            dp=cur;
        }
        int ans=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j)
                ans=max(ans,dp[i][j]);
        return ans;
    }
};