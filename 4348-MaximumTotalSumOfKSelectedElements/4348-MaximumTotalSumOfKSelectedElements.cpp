// Last updated: 30/6/2026, 11:52:11 am
using ll = long long;
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        ll ans = 0;
        for(int i=n-1;i>=n-k;--i){
            if(mul>0) ans+= 1LL*nums[i]*mul*1LL;
            else ans+= nums[i];
            mul--;
        }
        return ans;
    }
};