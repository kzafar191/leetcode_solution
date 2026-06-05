// Last updated: 5/6/2026, 5:06:05 pm
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(),ans=0;
        int sum = 0;
        for(int i=0;i<n;++i) sum+=nums[i];
        for(int i=0;i<n-1;++i){
            sum-=nums[i];
            int avg = sum/(n-i-1);
            if(nums[i]>avg) ans++;
        }
        return ans;
    }
};