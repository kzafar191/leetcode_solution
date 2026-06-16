// Last updated: 16/6/2026, 1:58:16 pm
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int prev = 0;
        int cnt=0;
        while(n>0){
            if(n&1){
                if(prev==1) cnt++;
            }
            prev = n&1;
            n/=2;
        }
        return cnt==1;
    }
};