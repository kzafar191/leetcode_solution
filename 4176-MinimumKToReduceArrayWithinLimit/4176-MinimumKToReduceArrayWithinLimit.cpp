// Last updated: 5/6/2026, 5:06:36 pm
class Solution {
public:

    bool check(vector<int>& nums,int k){
        long long tot = 0;
        long long lim = 1LL*k*k;

        for(int x:nums){
            tot +=(x+k-1)/k;
            if(tot>lim) return false;
        }
        return tot<=lim;
    }
    
    int minimumK(vector<int>& nums) {
        int n = nums.size();

        int mx = -1;
        for(int i=0;i<n;++i){
            if(nums[i]>mx) mx = nums[i];
        }
        int s=1,e=max(mx,n),ans=mx;
        while(s<=e){
            int mid = (s+e)/2;
            if(check(nums,mid)){
                ans = mid;
                e=mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};