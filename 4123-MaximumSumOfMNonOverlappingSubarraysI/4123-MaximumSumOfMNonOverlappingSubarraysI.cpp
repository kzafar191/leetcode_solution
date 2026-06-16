// Last updated: 16/6/2026, 1:59:53 pm
using ll = long long;

class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1e15));
        dp[0][0] = 0;

        long long ans = -1e17;

        vector<ll> p(n+1,0);

        for(int i=0;i<n;++i) p[i+1]=p[i]+nums[i];

        for(int i=0;i<=n;++i) dp[0][i] = 0;

        for(int j=1;j<=m;++j){
            deque<int> q;

            for(int i=1;i<=n;++i){
                dp[j][i] = dp[j][i-1];
                int k=i-l;

                if(k>=0 && dp[j-1][k]>-1e14){
                    ll v = dp[j-1][k]-p[k];
                    while(q.size()&&dp[j-1][q.back()]-p[q.back()]<=v) q.pop_back();
                    q.push_back(k);
                }
                while(q.size() && q.front() <i-r) q.pop_front();
                if(q.size()) dp[j][i] = max(dp[j][i],dp[j-1][q.front()]-p[q.front()]+p[i]);
            }

            ans = max(ans,dp[j][n]);
        }
        return ans;
    }
};