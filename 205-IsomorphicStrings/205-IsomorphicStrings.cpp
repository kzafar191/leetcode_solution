// Last updated: 5/6/2026, 5:09:54 pm
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> chart;
        unordered_map <char,bool> ch;

        int n=s.size();
        for(int i=0;i<n;++i){
            if(chart[s[i]]=='\0') {
                if(ch[t[i]]) return false;
                chart[s[i]]=t[i];
                ch[t[i]]=true;
            }
            if(chart[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};