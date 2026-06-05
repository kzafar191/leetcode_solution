// Last updated: 5/6/2026, 5:10:46 pm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],ans=nums[0],i=1;
        while(i<nums.size()){
            while(sum>=0 && i<nums.size()){
                sum+=nums[i];
                if(sum>ans) ans=sum;
                i++;
            }
            sum=0;
        }
        return ans;
    }
};