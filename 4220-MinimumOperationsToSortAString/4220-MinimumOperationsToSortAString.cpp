// Last updated: 5/6/2026, 5:05:59 pm
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int freqmn = 0, freqmx = 0;
        string str = s;
        char mn='z', mx='a';
        for(int i=0;i<n;++i){
            mn = min(mn,s[i]);
            mx = max(mx,s[i]);
        }
        for(int i=0;i<n;++i){
            if(s[i]==mn) freqmn++;
            if(s[i]==mx) freqmx++;
        }
        for(int i=1;i<n;++i){
            if(s[i]<s[i-1]) break;
            if(i==n-1) return 0;
        }
        if(n==2) return -1;
        if(n==1) return 0;
        if(mn == s[0] || mx == s[n-1]) return 1;
        if(mn == s[n-1] && mx == s[0] && freqmx==1 && freqmn ==1) return 3;
        return 2;
    }
};