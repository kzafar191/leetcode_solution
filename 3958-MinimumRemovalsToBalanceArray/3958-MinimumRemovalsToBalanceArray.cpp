// Last updated: 5/6/2026, 5:07:45 pm
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n= nums.size(),ans=nums.size();
        sort(nums.begin(),nums.end());
        int curr=n-1;
        for(int i=n-1;i>=0;--i){
            while(1LL*nums[curr]*k>=nums[i]*1LL){
                if(ans > n-(i-curr+1)) ans = n-i+curr-1;
                curr--;
                if(curr==-1) return ans;
            }
        }
        return ans;
    }
};