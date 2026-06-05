// Last updated: 5/6/2026, 5:08:40 pm
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int i=n-1;
        while(i>=0){
            if((num[i]-'0')&1){
                return num;
            }
            else{
                num.pop_back();
            }
            i--;
        }
        return num;
    }
};