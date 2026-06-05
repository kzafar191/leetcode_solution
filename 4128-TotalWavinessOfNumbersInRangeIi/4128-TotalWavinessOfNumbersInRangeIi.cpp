// Last updated: 5/6/2026, 5:06:59 pm
class Solution {
    pair<long long,long long> dp[16][2][2][11][11];
    string str;

    pair<long,long> solve(int pos, int tight, int zero, int prev1, int prev2){
        if(pos==str.size()) return {0,1};
        if(dp[pos][tight][zero][prev1][prev2].first!=-1) return dp[pos][tight][zero][prev1][prev2];

        int l = tight==1?str[pos]-'0':9;
        long long cnt=0;
        long long wav=0;

        for(int d=0;d<=l;++d){
            int nt = tight && d==l;
            int nz = zero && d==0;

            int np1 = nz?10:d;
            int np2 = nz?10:prev1;

            int w = 0;
            if (!nz&&prev1 != 10 && prev2 != 10) {
                if ((prev2 < prev1 && prev1 > d) || (prev2 > prev1 && prev1 < d)) {
                    w = 1;
                }
            }

            auto nxt = solve(pos+1,nt,nz,np1,np2);
            cnt+=nxt.second;
            wav+=nxt.second*w + nxt.first;

        }
        return dp[pos][tight][zero][prev1][prev2] = {wav,cnt};
    }
long long calc(long long n) {
        str = to_string(n);
        
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    for(int l = 0; l < 11; l++)
                        for(int m = 0; m < 11; m++)
                            dp[i][j][k][l][m] = {-1, -1};
                            
        return solve(0, 1, 1, 10, 10).first;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};