// Last updated: 5/6/2026, 5:07:13 pm
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<bool> sign(n+1);
        if(1LL*n*(n+1)/2 < abs(target)) return {};
        long long sub = 1LL*n*(n+1)/2 - target;
        for(int i=n;i>0;--i){
            if(2*i<=sub){
                sub-=2*i;
                sign[i] = true;
            }
            else sign[i] = false;
        }
        if(sub!=0) return {};
        vector<int> ans(n);
        for(int i=1;i<=n;++i){
            ans[i-1] = i;
            if(sign[i]) ans[i-1]*=-1;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};