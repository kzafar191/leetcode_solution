// Last updated: 10/7/2026, 8:33:55 am
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int l = s.size();
        int n = t.size();
        if(l>n) return false;
        if(l==1) return true;

        int last = -1;
        int prev = -1;
        int curr = 0;
        int i=0;
        for(i;i<l;++i){
            bool fnd = false;
            for(curr;curr<n;++curr){
                if(t[curr]==s[i]){
                    prev = last;
                    last = curr;
                    fnd = true;
                    break;
                }
            }
            if(curr>=n) break;
            curr++;
        }
        //if(l==2 && i==1 && last)
        int tk = i;
        if(i==l) return true;
        //if(curr<n ) return true;

        curr = last+2;
        if(last+1<n){
            for(++i;i<l;++i){
                for(curr;curr<n;++curr){
                    if(t[curr]==s[i]){
                        break;
                    }
                }
                if(curr>=n) break;
                curr++;
            }
            if(i==l) return true;
        }
        if(tk<=0) return false;
        
        curr = prev+2;
        i= tk;
        for(i;i<l;++i){
            for(curr;curr<n;++curr){
                if(t[curr]==s[i]){
                    break;
                }
            }
            if(curr>=n) break;
            curr++;
        }
        if(i==l) return true;
        return false;
    }
};