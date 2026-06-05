// Last updated: 5/6/2026, 5:08:03 pm
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minp = 1600;
        for(int i=0;i<n;++i) minp = min(minp,items[i][1]);

        vector<int> val(n,1);

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0) val[i]++;
            }
        }

        vector<int> dp(budget+1, -1);
        dp[0]=0;

        for(int i=0;i<n;++i){
            int w = items[i][1];
            int v = val[i];
            for(int j= budget;j>=w;--j){
                if(dp[j-w]!= -1) dp[j] = max(dp[j-w]+v,dp[j]);
            }
        }

        int ans = 0;

        for(int w = 0; w<=budget;++w) if(dp[w]!=-1) ans = max(ans,dp[w]+(budget-w)/minp);

        return ans;
    }
};