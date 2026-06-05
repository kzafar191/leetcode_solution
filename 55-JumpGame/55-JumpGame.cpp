// Last updated: 5/6/2026, 5:10:44 pm
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==0){
                for(int j=i-1;j>=0;--j){
                    if(nums[j]>i-j) break;
                    if(j==0) return false;
                }
            }
        }
        return true;
    }
};