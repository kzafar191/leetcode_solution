// Last updated: 5/6/2026, 5:06:53 pm
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long sum=0;
        int n = s.size();

        for(int i=0;i<n;++i) sum+=cost[i];

        vector<long long> indcost(26,0);

        for(int i=0;i<n;++i){
            indcost[s[i]-'a']+=cost[i];
        }

        long long mn = 1e15;

        for(int i=0;i<26;++i) mn = min(mn,sum-indcost[i]);
        return mn;
    }
};