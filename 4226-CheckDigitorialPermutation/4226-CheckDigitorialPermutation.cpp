// Last updated: 5/6/2026, 5:05:55 pm
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10);
        fact[0] = 1;
        for(int i=1;i<10;++i) fact[i] = fact[i-1]*i;
        vector<int> dignum(10,0), digfac(10,0);
        int facsum = 0;
        while(n>0){
            dignum[n%10]++;
            facsum+=fact[n%10];
            n/=10;
        }
        while(facsum>0){
            digfac[facsum%10]++;
            facsum/=10;
        }
        for(int i=0;i<10;++i){
            if(digfac[i]!=dignum[i]) return false;
        }
        return true;
    }
};