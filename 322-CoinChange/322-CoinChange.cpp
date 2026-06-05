// Last updated: 5/6/2026, 5:09:42 pm
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0] = 0;
        for(int coin: coins){
            for(int j=coin;j<=amount;++j){
                dp[j] = min(dp[j-coin]+1,dp[j]);
            }
        }
        if(dp[amount]==1e9) return -1;
        return dp[amount];
    }
};