// Last updated: 5/6/2026, 5:11:12 pm
class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size();
        while(i<n && isspace(s[i])) i++;

        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')) {
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }

        long result=0;
        while(i<n && isdigit(s[i])) {
            result = result*10 + (s[i]-'0');
            if(sign==1 && result>INT_MAX) return INT_MAX;
            if(sign==-1 && -result<INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign*result);
    }
};
