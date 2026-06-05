// Last updated: 5/6/2026, 5:08:49 pm
class Solution {
public:
    int minimumDeletions(string s) {
        int d=0,b=0;
        for(char c:s)
            if(c=='b')b++;
            else d=min(d+1,b);
        return d;
    }
};