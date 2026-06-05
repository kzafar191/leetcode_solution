// Last updated: 5/6/2026, 5:07:57 pm
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<int> h(m-1),v(n-1);
        long long sum=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j) sum+=grid[i][j];
        }
        long long ans=0;
        for(int i=0;i<m-1;++i){
            for(int j=0;j<n;++j){
                ans+=grid[i][j];
            }
            if(2*ans==sum) return true;
        }
        ans=0;
        for(int i=0;i<n-1;++i){
            for(int j=0;j<m;++j){
                ans+=grid[j][i];
            }
            if(2*ans==sum) return true;
        }
        return false;
    }
};