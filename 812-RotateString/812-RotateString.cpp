// Last updated: 5/6/2026, 5:09:19 pm
class Solution {
public:
    vector<int> computeLPS(const string &str){
        int n=str.size();
        vector<int> lps(n);
        int len=0; 
        lps[0]=0;
        for(int i=1;i<n;++i){
            while(len>0 && str[i]!=str[len]) len=lps[len-1];
            if(str[i]==str[len]) len++;
            lps[i]=len;
        }
        return lps;
    }

    bool rotateString(string s, string goal) {
        s+=s;
        int ss=s.size(), gs=goal.size();
        if(ss!=2*gs) return false;
        vector<int> lpsArr = computeLPS(goal);
        int i=0, j=0;
        while(i<ss){
            if(goal[j]==s[i]){
                i++;
                j++;
            }
            else if(j>0) j=lpsArr[j-1];
            else i++;
            if(j==gs) return true;
        }
        return false;
    }
};
