// Last updated: 5/6/2026, 5:05:06 pm
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> dig(10,0);
        string str = to_string(n);
        for(int i=0;i<str.size();++i){
            dig[str[i]-'0']++;
        }
        int sum =0;
        for(int i=0;i<=9;++i){
            sum+=dig[i]*i;
        }
        return sum;
    }
};