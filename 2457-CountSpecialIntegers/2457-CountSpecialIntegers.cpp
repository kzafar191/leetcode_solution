// Last updated: 5/6/2026, 5:08:24 pm
using ll = long long;

class Solution {

    int dp[11][2][2][1024];
    string str;
    
    int solve(int i,int t,int z,int m){
        if(i==str.size()) return z==1?0:1;

        if(dp[i][t][z][m]!=-1) return dp[i][t][z][m];
        int lim = t==1?str[i]-'0':9;
        int cnt=0;

        for(int d=0;d<=lim;++d){
            int nt = t && d==lim;
            int nz = z && d==0;
            if(z==1 && d==0){
                cnt+= solve(i+1,nt,1,0);
                continue;
            }

            if(m &(1<<d)) continue;
            int nm = m|(1<<d);
            cnt+= solve(i+1,nt,0,nm);
        }
        return dp[i][t][z][m]=cnt;
    }

public:
    int countSpecialNumbers(int n) {
        str = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,0);
    }
};