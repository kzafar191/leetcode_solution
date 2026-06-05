// Last updated: 5/6/2026, 5:08:43 pm
class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        long long sum=0;
        for(int i=0;i<n;++i){
            vector<int>freq(128,0);
            int mn=INT_MAX,mx=0;
            for(int j=i;j<n;++j){
                freq[s[j]]++;
                if(freq[s[j]]>mx) mx=freq[s[j]];
                mn=INT_MAX;
                for(int k=0;k<128;++k){
                    if(freq[k]!=0 && freq[k]<mn) mn=freq[k];
                }
                sum+=mx-mn;
            }
        }
        return (int)sum;
    }
};