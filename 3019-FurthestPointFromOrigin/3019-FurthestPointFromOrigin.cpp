// Last updated: 5/6/2026, 5:08:13 pm
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int dist=0;
        int dash=0;
        for(int i=0;i<n;++i){
            if(moves[i]=='R') dist++;
            else if(moves[i]=='L') dist--;
            else dash++;
        }
        return abs(dist) +dash;
    }
};