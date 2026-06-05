// Last updated: 5/6/2026, 5:05:51 pm
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> presum(n+1,0), postprod(n+1,1);
        for(int i=0;i<n;++i){
            presum[i+1] = presum[i]+nums[i];
        }
        int tk=0;
        for(int i=n-1;i>=0;--i){
            if(postprod[i+1] > 100000000000000LL / nums[i]) break;
            postprod[i] = postprod[i+1]*nums[i];
            if(i==0) continue;
            tk = i;
        }
        for(int i=max(tk-1,0);i<n;++i){
            if(postprod[i+1]==presum[i]) return i;
        }
        return -1;
    }
};