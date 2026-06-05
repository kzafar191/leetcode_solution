// Last updated: 5/6/2026, 5:08:11 pm
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin()+1,nums.end());
        return (nums[0]+nums[1]+nums[2]);
    }
};