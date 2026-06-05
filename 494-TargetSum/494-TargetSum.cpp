// Last updated: 5/6/2026, 5:09:33 pm
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum) return 0;
        target = sum+target;
        int n = nums.size();
        for(int i=0;i<n;++i) nums[i]*=2;
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<n;++i){
            for(int j=target;j>=nums[i];--j){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};