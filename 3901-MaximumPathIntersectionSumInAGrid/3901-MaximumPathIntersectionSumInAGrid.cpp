// Last updated: 5/6/2026, 5:07:53 pm
class Solution {
public:

    int func(vector<int>& arr){
        if(arr.size()<2) return INT_MIN;
        int n = arr.size();

        vector<int> pref(n+1,0);
        for(int i=0;i<n;++i) pref[i+1] = pref[i]+arr[i];

        int maxsum= INT_MIN;
        int minpref = pref[0];

        for(int k=2;k<=n;++k){
            minpref = min(minpref,pref[k-2]);
            maxsum = max(maxsum,pref[k]-minpref);
        }
        return maxsum;
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxsum = -1e9;

        for(int i=0;i<m;++i){
            maxsum = max(maxsum,func(grid[i]));
        }

        for(int i=0;i<n;++i){
            vector<int> col(m);

            for(int j=0;j<m;++j) col[j] = grid[j][i];

            maxsum = max(maxsum,func(col));
        }

        for(int i=1;i<m-1;++i){
            for(int j=1;j<n-1;++j) maxsum = max(maxsum,grid[i][j]);
        }
        return maxsum;
    }
};