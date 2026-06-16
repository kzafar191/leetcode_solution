// Last updated: 16/6/2026, 2:00:01 pm
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]*=nums[i];
        }
        long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            ans-=nums[i];
        }
        for(int i=n/2;i<n;i++){
            ans+=nums[i];
        }
        return ans;
    }
};