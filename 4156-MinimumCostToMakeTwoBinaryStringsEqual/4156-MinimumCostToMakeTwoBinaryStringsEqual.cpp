// Last updated: 5/6/2026, 5:06:46 pm
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int costeq = min(2*flipCost,crossCost);
        int costre = min(2*flipCost,crossCost);
        int mist = 0,n=s.size();
        int diff=0;
        for(int i=0;i<n;++i){
            if(s[i]!=t[i]) mist++;
            if(s[i]=='1') diff++;
            if(t[i]=='1') diff--;
        }
        diff = abs(diff);
        long long ans=0;
        if(diff&1){
            ans+=flipCost;
            diff--;
            mist--;
        }
        long long ans1 = 1LL*flipCost*diff + min(1LL*flipCost*(mist-diff),1LL*swapCost*(mist-diff)/2);
        long long ans2 = 1LL*crossCost*(diff/2) + min(flipCost*1LL*(mist),1LL*swapCost*(mist)/2);
        
        return ans+min(ans1,ans2);
    }
};