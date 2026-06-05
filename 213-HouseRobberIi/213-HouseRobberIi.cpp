// Last updated: 5/6/2026, 5:09:51 pm
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        if(n==1){
            return nums[0];
        }
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2;i<n;++i){
            dp[i]= max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        int f = dp[n-1];
        dp[1]=nums[1];
        for(int i=2;i<n;++i){
            dp[i]= max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(dp[n-1],f);
    }
};