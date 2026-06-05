// Last updated: 5/6/2026, 5:06:47 pm
class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        long long ans=0;
        for(int i=30;i>=0;--i){
            long long t=ans|(1LL<<i),sum=0;
            vector<long long> c;
            for(long long x:nums){
                if((x&t)==t) c.push_back(0);
                else{
                    long long d=t&~x,h=63-__builtin_clzll(d);
                    long long v=((x>>h|1)<<h)|t;
                    c.push_back(v-x);
                }
            }
            if(c.size()<m) continue;
            nth_element(c.begin(),c.begin()+m,c.end());
            for(int j=0;j<m;++j) sum+=c[j];
            if(sum<=k) ans=t;
        }
        return ans;
    }
};