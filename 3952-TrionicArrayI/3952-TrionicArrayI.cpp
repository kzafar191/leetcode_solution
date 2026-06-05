// Last updated: 5/6/2026, 5:07:48 pm
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n==3) return false;
        for(int i=0;i<n-1;++i){
            if(nums[i] == nums[i+1]) return false;
        }

        int p=0,q=n-1;
        int phase = 0;
        for(int i=1;i<n;++i){
            if(phase ==0){
                if(nums[i]>nums[i-1]) continue;
                else{
                    p = i-1;
                    phase++;
                }
            }
            else if(phase==1){
                if(nums[i]<nums[i-1]) continue;
                else{
                    q = i-1;
                    phase++;
                }
            }
            else{
                if(nums[i]<nums[i-1]) return false;
            }
        }
        if(p==0 || q==n-1) return false;
        return true;
    }
};