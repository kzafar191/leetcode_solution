// Last updated: 5/6/2026, 5:09:27 pm
class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(int l=0;l<moves.size();++l){
            if(moves[l]=='L') i--;
            else if(moves[l]=='R') i++;
            else if(moves[l]=='U') j++;
            else if(moves[l]=='D') j--;
        }
        return i==0&&j==0;
    }
};