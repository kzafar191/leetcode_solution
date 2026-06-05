// Last updated: 5/6/2026, 5:05:58 pm
class Solution {
public:

    int expand(string &s, int l, int r){
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            l--;r++;
        }
        int curr = r-l-1;

        int l1=l,r1=r;
        if(l>=0) l1--;

        while(l1>=0 && r1<n && s[l1]==s[r1]){
            l1--;
            r1++;
        }
        curr = max(curr,r1-l1-1);

        int l2=l,r2=r;
        if(r<n) r2++;

        while(l2>=0 && r2<n && s[l2]==s[r2]){
            l2--;
            r2++;
        }

        curr = max(curr,r2-l2-1);
        return curr;
    }
    
    int almostPalindromic(string s) {
        int n = s.size();
        int ans=2;
        for(int i=0;i<n;++i){
            ans = max(ans,expand(s,i,i));
            if(i+1<n) ans = max(expand(s,i,i+1),ans);
        }
        return ans;
    }
};