// Last updated: 16/6/2026, 2:02:24 pm
using ll = long long;
class Solution {
    pair<ll,ll> dp[10][2];
    string str;

    pair<ll,ll> solve(int i,int tight){
        if(i==str.length()) return {0,1}; //0-0 ones -- 1-number of such numbers
        
        if(dp[i][tight].first!=-1) return dp[i][tight];

        ll cnt=0;
        ll one =0;

        ll lim = tight==1?str[i]-'0':9;
        for(int d=0;d<=lim;d++){
            int nt=tight && d==lim;

            auto nxt = solve(i+1,nt);
            cnt += nxt.second;
            one += nxt.first + nxt.second*(d==1); 
        }
        return dp[i][tight]={one,cnt};
    }
    
public:
    int countDigitOne(int n) {
        for(int i=0;i<10;++i){
            for(int j=0;j<2;++j) dp[i][j]={-1,-1};
        }
        str = to_string(n);
        return solve(0,1).first;
    }
};