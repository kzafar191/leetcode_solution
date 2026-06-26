// Last updated: 26/6/2026, 2:49:58 pm
using ll = long long;
string s;
int diff;
class Solution {
    ll dp[18][11][2][2];

    ll dig(int idx, int prev, int tight, int zero){

        if(idx==s.size()) return 1;
        
        if(dp[idx][prev+1][tight][zero] != -1) return dp[idx][prev+1][tight][zero];

        int lim = tight?(s[idx]-'0'):9;
        ll ans=0;

        for(int d=0;d<=lim;++d){
            int ntight = tight && d==lim;
            int nzero = zero && d==0;
            if(zero){
                if(d==0){
                    ans+= dig(idx+1,-1,ntight,1);
                }
                else ans+=dig(idx+1,d,ntight,0);
                continue;
            }
            if(abs(d-prev)<=diff) ans+= dig(idx+1,d,ntight,0);
        }
        dp[idx][prev+1][tight][zero] = ans;
        return dp[idx][prev+1][tight][zero];
    }

    ll num(ll n){
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return dig(0,-1,1,1);
    }
    
public:
    long long goodIntegers(long long l, long long r, int k) {
        diff = k;
        return num(r)-num(l-1);
    }
};