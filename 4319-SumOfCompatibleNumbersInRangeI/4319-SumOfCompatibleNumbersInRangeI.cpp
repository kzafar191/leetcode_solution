// Last updated: 16/6/2026, 1:58:00 pm
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int x=1;x<=200;++x){
            if(abs(n-x)<=k){
                if((n&x)==0) sum+=x;
            }
        }
        return sum;
    }
};