// Last updated: 16/6/2026, 2:02:04 pm
class Solution {
    int dp[35][2][2][2];
    string str;
    int solve(int idx,int tight,int prev,int zero){
        if(idx==str.size()) return zero?0:1;
        if(dp[idx][tight][prev][zero]!=-1) return dp[idx][tight][prev][zero];

        int ans = 0;
        int lim = tight?str[idx]-'0':1;
        
        for(int d=0;d<=lim;++d){
            int nt = tight && d==lim;
            int nz = zero && d==0;
            if(prev==1 && d==1) continue;
            ans+=solve(idx+1,nt,d,nz);
        }
        return dp[idx][tight][prev][zero]=ans;
    }
public:
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        while(n>0){
            if(n&1) str+='1';
            else str+='0';
            n/=2;
        }
        reverse(str.begin(),str.end());
        return solve(0,1,0,1)+1;
    }
};