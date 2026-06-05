// Last updated: 5/6/2026, 5:07:59 pm
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<int>>> presum(201,vector<vector<int>>(n+1,vector<int>(m+1)));

        for(int num=0;num<=200;++num){
            for(int i=0;i<=m;++i) presum[num][0][i] = 0;
            for(int i=0;i<n;++i){
                presum[num][i+1][0] = 0;
                for(int j=0;j<m;++j){
                    presum[num][i+1][j+1] = presum[num][i+1][j]+(matrix[i][j]>num);
                } 
            }
            for(int i=0;i<=m;++i){
                for(int j=0;j<n;++j){
                    presum[num][j+1][i] += presum[num][j][i];
                }
            }
        }
        auto query = [&](int v, int i1,int i2,int j1,int j2){
            i1 = max(0, i1);
            j1 = max(0, j1);
            i2 = min(n - 1, i2);
            j2 = min(m - 1, j2);
            //if (1 > r2 || c1 > c2) return 0;
            
            return presum[v][i2+1][j2+1] - presum[v][i1][j2+1] - presum[v][i2+1][j1] + presum[v][i1][j1];
        };

        int cnt=0;
        for (int i=0; i<n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = matrix[i][j];
                if (x == 0) continue; 
                
                int total_greater = query(x, i - x, i + x, j - x, j + x);
                
                if (i - x >= 0 && j - x >= 0 && matrix[i-x][j-x] > x) total_greater--;
                if (i - x >= 0 && j + x < m  && matrix[i-x][j+x] > x) total_greater--;
                if (i + x < n  && j - x >= 0 && matrix[i+x][j-x] > x) total_greater--;
                if (i + x < n  && j + x < m  && matrix[i+x][j+x] > x) total_greater--;
                
                if (total_greater == 0) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};