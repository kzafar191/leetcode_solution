// Last updated: 5/6/2026, 5:06:50 pm
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        long long ans =0;
        for(int i=1;i<n-1;i+=2){
            if(n%2==0) break;
            if(nums[i]<=nums[i-1]){
                ans+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
            if(nums[i]<=nums[i+1]){
                ans+=nums[i+1]-nums[i]+1;
                nums[i]=nums[i+1]+1;
            }
        }
        if(n&1) return ans;

        vector<vector<long long>> dp(n,vector<long long>(2,1e17));

        //for(int i=0;i<n;++i) dp[i]={1e17,1e17};
        
        dp[1][0]=max(nums[0],nums[2])>=nums[1]?max(nums[0],nums[2])-nums[1]+1:0;
        dp[2][1]=max(nums[1],nums[3])>=nums[2]?max(nums[1],nums[3])-nums[2]+1:0;

        for(int i=3;i<n-1;++i){
            long long add = max(nums[i-1],nums[i+1])>=nums[i]?max(nums[i-1],nums[i+1])-nums[i]+1:0;
            dp[i][0] = dp[i-2][0]+add;
            dp[i][1] = min(dp[i-2][1],dp[i-3][0])+add;
        }
        return min(dp[n-3][0],dp[n-2][1]);
    }
};