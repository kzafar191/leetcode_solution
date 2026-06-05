// Last updated: 5/6/2026, 5:07:42 pm
class Solution {
public:
	vector<vector<int>>reverseSubmatrix(vector<vector<int>>&grid,int x,int y,int k){
        
		for(int i=0;i<k/2;++i){
			int r1=x+i;
			int r2=x+k-1-i;
			for(int j=0;j<k;++j) swap(grid[r1][y+j],grid[r2][y+j]);
		}
		return grid;
	}
};
