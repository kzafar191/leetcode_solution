// Last updated: 5/6/2026, 5:06:13 pm
class Solution {
public:
    string reverseByType(string s) {
        string a = "", b = "";
        for(char c:s){
            if(islower(c)) a+=c;
            else b+=c;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        for(char &c :s){
            if(islower(c)) c= a[i++];
            else c = b[j++];
        }
        return s;
    }
};