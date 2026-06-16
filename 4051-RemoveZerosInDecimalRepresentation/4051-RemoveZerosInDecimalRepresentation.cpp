// Last updated: 16/6/2026, 2:00:13 pm
class Solution {
public:
    long long removeZeros(long long n) {
        string str ="";
        while(n>0){
            int digit = n%10;
            n/=10;
            if(digit!=0){
                str += to_string(digit);
            }
        }
        reverse(str.begin(), str.end());
        return stoll(str);
    }
};