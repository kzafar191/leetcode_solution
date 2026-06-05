// Last updated: 5/6/2026, 5:09:18 pm
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cup(101,vector<double>(101,0));
        cup[0][0] = poured;

        for(int i=0;i<100;++i){
            for(int j=0;j<=i;++j){
                double extra = cup[i][j]-1;
                if(extra<=0) continue;
                cup[i][j] = 1;
                cup[i+1][j] += extra/2;
                cup[i+1][j+1] += extra/2;
            }
        }
        return cup[query_row][query_glass];
    }
};