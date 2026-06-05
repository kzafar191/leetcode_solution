// Last updated: 5/6/2026, 5:07:02 pm
class Solution {
public:

    string num;
    vector<vector<vector<long long>>> dp;
    vector<bool> path;

    long long recur(int idx, int tight, int lastdig){
        if(idx==16) return 1;

        if(dp[idx][tight][lastdig]!=-1) return dp[idx][tight][lastdig];

        int till=9;
        //if(path[idx]) till = min(lastdig,till);
        if(tight) till = min(till,num[idx]-'0');
        int next =lastdig;
        long long tot =0;
        for(int d=0;d<=till;++d){
            if(path[idx] && d<lastdig) continue;
            if(path[idx]) next = d;
            int nexttight = (tight&&(d==(num[idx]-'0')));
            tot+= recur(idx+1, nexttight, next);
        }
        dp[idx][tight][lastdig] = tot;
        return dp[idx][tight][lastdig];
    }

    long long answer(long long l){
        dp.assign(16,vector<vector<long long>>(2,vector<long long>(10,-1)));
        num = to_string(l);
        reverse(num.begin(), num.end());
        while(num.size()!=16) num+='0';
        reverse(num.begin(),num.end());

        return recur(0,1,0);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        path.assign(16,false);
        int v=0;
        path[v] = true;
        for(int i=0;i<6;++i){
            if(directions[i]=='D') v+=4;
            else v++;
            path[v]=true;
        }
        return answer(r) - answer(l-1);
    }
};