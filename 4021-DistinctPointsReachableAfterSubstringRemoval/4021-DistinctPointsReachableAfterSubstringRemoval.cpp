// Last updated: 5/6/2026, 5:07:34 pm
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size(),ans=0;
        
        set <pair<int,int>> track;

        vector<int> u(n+1,0),d(n+1,0),l(n+1,0),r(n+1,0);
        for(int i=0;i<n;++i){
            u[i+1] = u[i];
            l[i+1] = l[i];
            r[i+1] = r[i];
            d[i+1] = d[i];
            if(s[i]=='U') u[i+1]++;
            if(s[i]=='L') l[i+1]++;
            if(s[i]=='R') r[i+1]++;
            if(s[i]=='D') d[i+1]++;
        }

        pair<int,int> P;
        P = {0,0};

        for(int i=0;i<n;++i){
            if(s[i]=='U') P.first++;
            if(s[i]=='L') P.second--;
            if(s[i]=='D') P.first--;
            if(s[i]=='R') P.second++;
        }
        
        for(int i=0;i<=(n-k);++i){
            pair<int,int> temp;
            temp = P;

            int U = u[i+k]-u[i];
            int L = l[i+k]-l[i];
            int D = d[i+k]-d[i];
            int R = r[i+k]-r[i];

            temp.first -= (U-D);
            temp.second -= (R-L);

            track.insert(temp);
        }
        return track.size();
    }
};