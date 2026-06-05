// Last updated: 5/6/2026, 5:07:52 pm
class Solution {
public:
    bool checkDivisibility(int n) {
        int nn = n;
        int sum = 0, prod = 1;
        while(n>0){
            sum += n%10;
            prod *= n%10;
            n/=10;
        }
        sum+=prod;
        if(nn%sum == 0) return true;
        else return false;
    }
};