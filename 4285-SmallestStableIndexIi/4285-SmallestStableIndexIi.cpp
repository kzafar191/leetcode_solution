// Last updated: 5/6/2026, 5:05:19 pm
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefmx(n,0), suffmn(n,INT_MAX);
        suffmn[n-1] = nums[n-1];
        prefmx[0] = nums[0];
        for(int i=1;i<n;++i){
            prefmx[i]= max(prefmx[i-1],nums[i]);
            suffmn[n-i-1] = min(suffmn[n-i],nums[n-i-1]);
        }
        for(int i=0;i<n;++i){
            if(prefmx[i]-suffmn[i]<=k) return i;
        }
        return -1;
    }
};