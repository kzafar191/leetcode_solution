// Last updated: 26/6/2026, 2:49:51 pm
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);

        for(int i=0;i<m;++i){
            string s = "";
            for(int j=0;j<n;++j){
                if(j==n-1) s+='.';
                else s+='#';
            }
            ans[i] = s;
        }
        for(int i=0;i<n-1;++i) ans[0][i] = '.';
        return ans;
    }
};