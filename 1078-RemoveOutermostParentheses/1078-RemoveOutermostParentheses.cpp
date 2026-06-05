// Last updated: 5/6/2026, 5:09:09 pm
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ns="";
        int lst=0,sm=1;
        for(int i=1;i<n;++i){
            if(s[i]=='(') sm++;
            else sm--;
            if(sm) ns+=s[i];
            else {i++; sm=1;}
        }
        return ns;
    }
};