// Last updated: 5/6/2026, 5:06:27 pm
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();
        vector<int> dis(n);
        for(int i=0;i<n;++i){
            int d = abs(towers[i][0]-center[0]) + abs(towers[i][1]-center[1]);
            dis[i] = d;
        }
        int qual=-1;
        vector<int> ans = {-1,-1};
        for(int i=0;i<n;++i){
            if(dis[i]<=radius && towers[i][2]>=qual){
                if(qual == towers[i][2]){
                    if(ans[0]<towers[i][0]){
                        continue;
                    }
                    else if(ans[0]==towers[i][0] && ans[1]<towers[i][1]){
                        continue;
                    }
                }
                qual = towers[i][2];
                ans[0] = towers[i][0];
                ans[1] = towers[i][1];
            }
        }
        return ans;
    }
};