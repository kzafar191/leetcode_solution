// Last updated: 5/6/2026, 5:08:31 pm
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        vector<vector<int>> col(101);
        vector<bool> vis(101,false);

        int n = colors.size();
        for(int i=0;i<n;++i){
            if(vis[colors[i]]) continue;
            col[colors[i]].push_back(i);
            vis[colors[i]] = true;
        }

        vis.assign(101,false);
        for(int i=n-1;i>=0;--i){
            if(vis[colors[i]]) continue;
            col[colors[i]].push_back(i);
            vis[colors[i]] = true;
        }

        int l1=1e3, l2=1e3, h1=-1, h2=-1;
        for(int i=0;i<101;++i){
            if(col[i].size()==0) continue;
            if(col[i][0]<l2) l2 = col[i][0];
            if(col[i][col[i].size()-1]>h2) h2 = col[i][col[i].size()-1];

            if(l2<l1) swap(l1,l2);
            if(h2>h1) swap(h1,h2);
        }
        if(colors[h1]!=colors[l1]) return abs(h1-l1);
        else{
            int a = abs(h1-l2);
            int b = abs(h2-l1);
            return max(a,b);
        }
    }
};