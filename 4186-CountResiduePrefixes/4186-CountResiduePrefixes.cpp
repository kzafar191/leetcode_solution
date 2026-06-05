// Last updated: 5/6/2026, 5:06:23 pm
class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> alph(26,0);
        int n = s.size();

        int unq =0, ans=0;
        for(int i=0;i<n;++i){
            if(alph[s[i]-'a']==0){
                unq++;
            }
            if((i+1)%3==unq) ans++;
            alph[s[i]-'a']++;
        }
        return ans;
    }
};