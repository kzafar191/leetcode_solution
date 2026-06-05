// Last updated: 5/6/2026, 5:09:45 pm
class Solution{
public:
	bool searchMatrix(vector<vector<int>>&matrix,int target){
		if(matrix.empty()||matrix[0].empty()) return false;
		int m=matrix.size(), n=matrix[0].size();
		for(int i=0;i<m;++i){
			if(target < matrix[i][0] || target > matrix[i][n-1]) continue;

			int l=0, r=n-1;
			while(l<=r){
				int mid = l + (r-l)/2;
				int v = matrix[i][mid];
				if(v==target) return true;
				if(v<target) l=mid+1;
				else r=mid-1;
			}
		}
		return false;
	}
};