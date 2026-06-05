// Last updated: 5/6/2026, 5:08:44 pm
class Solution {
public:
    bool check(vector<int>& nums) {
        int dis = 0;
        for(int i=1;i<nums.size();++i){
            if(nums[i-1]>nums[i]) dis++;
            if(dis==2) return false;
        }
        if(dis==1) {
            if(nums[nums.size()-1]>nums[0]) return false;
            else return true;
        }
        return true;
    }
};