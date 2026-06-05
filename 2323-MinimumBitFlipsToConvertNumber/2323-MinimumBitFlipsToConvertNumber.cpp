// Last updated: 5/6/2026, 5:08:26 pm
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start!=0 || goal!=0){
            ans += (start&1)^(goal&1);
            start/=2;
            goal/=2;
        }
        return ans;
    }
};