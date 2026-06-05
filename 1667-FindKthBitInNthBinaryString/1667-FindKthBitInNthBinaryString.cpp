// Last updated: 5/6/2026, 5:08:52 pm
class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string> N(20);
        N[0] = "0";
        for(int i=1;i<20;++i){
            N[i] = N[i-1];
            N[i]+='1';
            for(int l=0;l<N[i-1].size();++l){
                N[i] += !(N[i-1][N[i-1].size()-1-l]-'0') + '0';
            }
        }
        return N[n-1][k-1];
    }
};