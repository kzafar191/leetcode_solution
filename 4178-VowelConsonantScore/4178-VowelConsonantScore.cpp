// Last updated: 5/6/2026, 5:06:33 pm
class Solution {
public:
    int vowelConsonantScore(string s) {
        int  n = s.size();
        vector<char> vow(5);
        vow= {'a','e','i','o','u'};
        int v=0,c=0;
        for(int i=0;i<n;++i){
            if(s[i]> 'z' || s[i]<'a') continue;
            for(int j=0;j<5;++j){
                if(s[i] == vow[j]) {v++; break;}
                if(j==4) c++;
            }
        }
        if(c==0) return 0;
        else return v/c;
    }
};