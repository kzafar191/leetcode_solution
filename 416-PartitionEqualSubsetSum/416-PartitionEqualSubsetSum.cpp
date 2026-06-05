// Last updated: 5/6/2026, 5:09:35 pm
class Solution {
public:
    bool can(vector<int>& nums, int target) {

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            if (dp[j - num] == true) {
                dp[j] = true;
            }
        }
    }

    return dp[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum&1) return false;
        else return can(nums, sum/2);
    }
};