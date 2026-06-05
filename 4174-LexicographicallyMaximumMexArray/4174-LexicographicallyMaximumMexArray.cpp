// Last updated: 5/6/2026, 5:06:38 pm
#define pb push_back

class Solution {
public:
    vector<int> maximumMEX(vector<int>& a) {
        vector<int> c(1e5+5,0), r, s;
        int m=0, i=0, j, z, t, n=a.size();
        
        for(int x:a) c[x]++;
        while(c[m]) m++;
        
        while(i<n) {
            t=m; z=0; s.assign(t+1,0);
            for(j=i; j<n; j++) {
                if(a[j]<t && !s[a[j]]) s[a[j]]=1, z++;
                if(--c[a[j]]==0 && a[j]<m) m=a[j];
                if(z==t) { r.pb(t); i=j+1; break; }
            }
        }
        return r;
    }
};