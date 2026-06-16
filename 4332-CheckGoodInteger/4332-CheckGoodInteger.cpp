// Last updated: 16/6/2026, 1:58:02 pm
class Solution {
public:
    bool checkGoodInteger(int n) {
        int dig = 0;
        int digs = 0;

        while(n>0){
            int r = n%10;
            dig+=r;
            digs += r*r;
            n/=10;
        }
        return digs-dig>=50;
    }
};