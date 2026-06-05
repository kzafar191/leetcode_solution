// Last updated: 5/6/2026, 5:07:01 pm
class Solution {
public:
    int minimumFlips(int n) {
        string ab = "";

        int i=0;
        while(n>0){
            if(n&(1<<i)){
                ab+="1";
                n-= (1<<i);
            }
            else ab+="0";
            i++;
        }
        int sz = ab.size(), ans =0;
        for(int i=0;i<sz/2;++i){
            if(ab[i]!=ab[sz-1-i]) ans+=2;
        }
        return ans;
    }
};