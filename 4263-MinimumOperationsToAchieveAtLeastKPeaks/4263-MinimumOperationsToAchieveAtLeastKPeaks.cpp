// Last updated: 5/6/2026, 5:05:41 pm
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n/2) return -1;
        if(k == 0) return 0;
        if(n == 2) return nums[0] == nums[1] ? 1 : 0;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 1e17));
        
        dp[0][0] = 0;
        dp[0][1] = max(nums[n-1], nums[1]) >= nums[0] ? max(nums[n-1], nums[1]) - nums[0] + 1 : 0;
        dp[1][0] = 0;
        dp[1][1] = max(nums[0], nums[2]) >= nums[1] ? max(nums[0], nums[2]) - nums[1] + 1 : 0;
        dp[1][1] = min(dp[1][1], dp[0][1]);
        
        for(int i = 2; i < n - 1; ++i) {
            dp[i][0] = 0;
            long long add = max(nums[i-1], nums[i+1]) >= nums[i] ? max(nums[i-1], nums[i+1]) - nums[i] + 1 : 0;
            for(int j = 1; j <= k; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + add);
            }
        }
        long long ans = dp[n-2][k];

        dp.assign(n, vector<long long>(k + 1, 1e17));
        
        dp[1][0] = 0;
        dp[2][0] = 0;
        dp[1][1] = max(nums[0], nums[2]) >= nums[1] ? max(nums[0], nums[2]) - nums[1] + 1 : 0;
        dp[2][1] = max(nums[1], nums[3%n]) >= nums[2] ? max(nums[1], nums[3%n]) - nums[2] + 1 : 0;
        dp[2][1] = min(dp[2][1], dp[1][1]);

        for(int i = 3; i < n; ++i) {
            dp[i][0] = 0;
            long long add = max(nums[i-1], nums[(i+1)%n]) >= nums[i] ? max(nums[i-1], nums[(i+1)%n]) - nums[i] + 1 : 0;
            for(int j = 1; j <= k; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + add);
            }
        }
        
        return min(ans, dp[n-1][k]);
    }
};