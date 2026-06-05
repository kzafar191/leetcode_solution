// Last updated: 5/6/2026, 5:06:24 pm
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> nums2(n);

        for(int i=0;i<n;++i) nums2[i] = nums[n-1-i];

        int err=0,idx;
        for(int i=1;i<n;++i){
            if(nums[i-1]!=nums[i]-1) {err++; idx=i;}
            if(err==2){
                break;
            }
        }
        if(err==0) return 0;
        else if(err==1) return min(idx,n-idx+2);
        else err=0;

        for(int i=1;i<n;++i){
            if(nums2[i-1]!=nums2[i]-1) {err++; idx=i;}
            if(err==2){
                break;
            }
        }
        if(err==0) return 1;
        else if(err==1) return min(1+idx,n-idx+1);
        else return -1;
    }
};