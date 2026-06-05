// Last updated: 5/6/2026, 5:10:34 pm
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int carry = 0;
        for(int i=0;i<max(a.size(),b.size());++i){
            int n1 = i<a.size()?a[i]-'0':0;
            int n2 = i<b.size()?b[i]-'0':0;
            int numb = n1+n2+carry;
            ans+=(numb%2)+'0';
            carry = numb/2;
        }
        if(carry) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};