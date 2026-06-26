// Last updated: 26/6/2026, 2:49:52 pm
class Solution {
public:
    int maxDistance(string moves) {
        int v=0,h=0;
        int u=0,d=0,l=0,r=0;
        int n = moves.size();
        for(int i=0;i<n;++i){
            if(moves[i]=='U') u++;
            else if(moves[i]=='L') l++;
            if(moves[i]=='D') d++;
            if(moves[i]=='R') r++;
        }
        int un = n-(u+d+l+r);
        return abs(u-d)+abs(l-r)+un;
    }
};