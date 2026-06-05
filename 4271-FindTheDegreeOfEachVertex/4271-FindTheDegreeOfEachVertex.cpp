// Last updated: 5/6/2026, 5:05:32 pm
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> deg(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) continue;
                if(matrix[i][j]) deg[i]++;
            }
        }
        return deg;
    }
};