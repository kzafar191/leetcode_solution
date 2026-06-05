// Last updated: 5/6/2026, 5:10:13 pm
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            ans = ans^nums[i];
        }
        return ans;
    }
};