// Last updated: 5/6/2026, 5:05:47 pm
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int mn = n;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(nums[i]+nums[j]==3) mn = min(mn,j-i);
            }
        }
        if(mn<n) return mn;
        return -1;
    }
};