// Last updated: 5/6/2026, 5:09:58 pm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        for(int i=1;i<nums.size();++i){
            if(!cnt){
                nums[0]=nums[i];
            }
            if(nums[i]==nums[0]){
                cnt++;
            }
            else cnt--;
        }
        return nums[0];
    }
};