// Last updated: 5/6/2026, 5:07:04 pm
class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0],nums[n-1]);
    }
};