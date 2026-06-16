// Last updated: 16/6/2026, 2:00:26 pm
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        int mn = INT_MAX,mn2 = INT_MAX;
        int idx = -1, idx2 = -1;
        for(int i=0;i<m;++i){
            sort(units[i].begin(),units[i].end());
            if(units[i][0]<mn){
                mn = units[i][0];
                idx = i;
            }
        }
        long long ans = 0;
        
        for(int i=0;i<m;++i){
            if(i==idx){
                ans+=mn;
                continue;
            }
            if(units[i].size()>1) ans+=units[i][1];
            else ans+=units[i][0];
        }
        for(int i=0;i<m;++i){
            if(units[i].size()==1) continue;
            mn2 = min(mn2,units[i][1]);
        }
        if(units[idx].size()==1 || mn2==INT_MAX) return ans;
        return ans+=(units[idx][1]-mn2);
    }
};