// Last updated: 10/7/2026, 8:33:57 am
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n,0),suffmax(n,0);

        premax[0] = nums[0];
        suffmax[0] = nums[n-1];

        for(int i=1;i<n;++i){
            premax[i] = max(premax[i-1],nums[i]);
            suffmax[n-1-i] = max(suffmax[n-i],nums[n-1-i]);
        }

        int ans = 0;
        for(int i=0;i<n;++i){
            int l = i-k;
            int r = i+k;
            ans = (l>=0?max(ans,nums[i]+premax[l]):ans);
            ans = r<n?max(ans,nums[i]+suffmax[r]):ans;
        }
        return ans;
    }
};