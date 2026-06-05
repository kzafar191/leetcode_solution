// Last updated: 5/6/2026, 5:06:31 pm
class Solution {
public:
    string largestEven(string s) {
        string ans = "";
        bool even = false;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]%2==0) even = true;

            if(even) ans+=s[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};