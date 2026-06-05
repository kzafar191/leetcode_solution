// Last updated: 5/6/2026, 5:06:17 pm
class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        ans =1;
        for(int i=1;;++i){
            if((1<<i)-1<=n) ans++;
            else break;
        }
        return ans;
    }
};