// Last updated: 5/6/2026, 5:06:14 pm
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-1;i>0;--i){
            if(nums[i]>nums[i-1]) continue;
            return i;
        }
        return 0;
    }
};