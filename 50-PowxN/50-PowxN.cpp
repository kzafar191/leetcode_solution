// Last updated: 5/6/2026, 5:10:48 pm
class Solution {
public:

    double poww(double ans, double x, long long int n){
        if(n>1){
            return poww(ans, x*x, n/2) * (n&1 ? x: 1);
        }else if(n < -1){
            
            return poww(ans,1/(x*x),-n/2) * (n&1 ? (1/x): 1);
        }else if(n == -1){
            return 1/x;
        }else return x;
        // if(n >0){
        //     ans *= x;
        //     return poww(ans, x, n-1);
        // }else if(n < 0 ){
        //     ans /= x;
        //     return poww(ans, x, n+1);
        // }else{
        //     return ans;
        // }

    }
    double myPow(double x, int n) {
        long long int N = n;
        if(N == 0 || x==1) return 1;
        return poww(1,x,N);
    }
};