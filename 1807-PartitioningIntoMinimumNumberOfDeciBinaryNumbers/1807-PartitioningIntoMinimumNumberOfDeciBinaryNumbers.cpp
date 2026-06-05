// Last updated: 5/6/2026, 5:08:46 pm
class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(int i=0;i<n.size();++i){
            ans = max(ans,n[i]-'0');
        }
        return ans;
    }
};