// Last updated: 5/6/2026, 5:08:50 pm
class Solution {
public:
    int maxDepth(string s) {
        int sm=0,mx=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') sm++;
            else if (s[i]==')') sm--;
            mx=max(mx,sm);
        }
        return mx;
    }
};