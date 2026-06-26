// Last updated: 26/6/2026, 2:50:11 pm
int mod = 1e9 +7;
using ll = long long;
//using int = long long;
class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        ll x=0;
        int n = value.size();
        ll s=1,e=1e9;

        int mid;
        while(s<=e){
            mid = (s+e)/2;
            ll mm = 0;

            for(int i=0;i<n;++i){
                if(mid>value[i]) continue;
                else if(mid==value[i]) mm++;
                else{
                    mm += (value[i] - mid) / decay[i] + 1;
                }
            }

            if(mm>=m) {x=mid;s=mid+1;}
            else{
                e=mid-1;
            }
        }
       // x = mid;

        ll ans=0;
        ll pick = 0;
        x++;
        for(int i=0;i<n;++i){
            if(value[i]<x) continue;
            ll mm = (value[i] - x) / decay[i]+1;
            pick+=mm;
            ll f = value[i];
            ll l = f - (mm - 1) * decay[i];
            
            ans += ((f + l) * mm) / 2;
            ans %= mod;
        }
        ll rem = m-pick;
        x--;
        if(rem>0 && x>0){
            ans = (ans + rem*x)%mod;
        }
        return ans;
    }
};