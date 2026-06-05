// Last updated: 5/6/2026, 5:10:05 pm
class Solution {
public:
    string reverseWords(string s) {
        string ns="";
        stack<char> st;
        int n=s.size();
        int i=n-1;
        while(i>=0){
            for(i;i>=0;i--){
                if(s[i]==' ') {i--;break;}
                else st.push(s[i]);
            }
            bool a=false;
            while(!st.empty()){
                a=true;
                ns+=st.top();
                st.pop();
            }
            if(a)ns+=' ';
        }
        ns.pop_back();
        return ns;
    }
};