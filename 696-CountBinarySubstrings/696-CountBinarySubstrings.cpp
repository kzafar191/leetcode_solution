// Last updated: 5/6/2026, 5:09:22 pm
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(),ans=0;
        int zero=0,one=0;
        for(int i=0;i<n;){
            while(s[i]=='0') {zero++;i++;}
            ans+=min(zero,one);
            one=0;
            while(s[i]=='1') {one++;i++;}
            ans += min(zero,one);
            zero=0;

        }
        return ans;
    }
};