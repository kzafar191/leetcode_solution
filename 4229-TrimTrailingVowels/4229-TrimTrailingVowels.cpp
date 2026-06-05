// Last updated: 5/6/2026, 5:05:54 pm
class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        int i=0;
        for(i=0;i<n;++i){
            if(s[i]=='a'|s[i]=='e'|s[i]=='i'|s[i]=='o'|s[i]=='u') continue;
            break;
        }
        string ans="";
        for(i;i<n;++i) ans+=s[i];
        reverse(ans.begin(),ans.end());
        return ans;
    }
};