// Last updated: 5/6/2026, 5:10:49 pm
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e5);
        dp[0] = 0;
        for(int i=0;i<n;++i){
            for(int j=1;j<=nums[i];++j){
                if(i+j>=n) break;
                dp[i+j] = min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};