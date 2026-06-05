// Last updated: 5/6/2026, 5:05:22 pm
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<vector<int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0)) , time(n,vector<int>(m,1e7));
        int src = sources.size();
        for(int i=0;i<src;++i){
            ans[sources[i][0]][sources[i][1]] = sources[i][2];
            q.push(sources[i]);
            time[sources[i][0]][sources[i][1]] = 0;
        }
        while(!q.empty()){
            vector<int> temp;
            temp = q.front();
            int r = temp[0], c = temp[1];
            int tm = time[r][c]+1;

            if(r-1>=0){
                if(time[r-1][c]> tm){
                    q.push({r-1,c});
                    time[r-1][c] = tm;
                    ans[r-1][c] = ans[r][c];
                }
                else if(time[r-1][c] == tm && ans[r][c]>ans[r-1][c]){
                    ans[r-1][c] = ans[r][c];
                    q.push({r-1,c});
                }
            }
            if(c-1>=0){
                if(time[r][c-1]> tm){
                    q.push({r,c-1});
                    time[r][c-1] = tm;
                    ans[r][c-1] = ans[r][c];
                }
                else if(time[r][c-1] == tm && ans[r][c]>ans[r][c-1]){
                    ans[r][c-1] = ans[r][c];
                    q.push({r,c-1});
                }
            }
            if(r+1<n){
                if(time[r+1][c]> tm){
                    q.push({r+1,c});
                    time[r+1][c] = tm;
                    ans[r+1][c] = ans[r][c];
                }
                else if(time[r+1][c] == tm && ans[r][c]>ans[r+1][c]){
                    ans[r+1][c] = ans[r][c];
                    q.push({r+1,c});
                }
            }
            if(c+1<m){
                if(time[r][c+1]> tm){
                    q.push({r,c+1});
                    time[r][c+1] = tm;
                    ans[r][c+1] = ans[r][c];
                }
                else if(time[r][c+1] == tm && ans[r][c]>ans[r][c+1]){
                    ans[r][c+1] = ans[r][c];
                    q.push({r,c+1});
                }
            }
            q.pop();
        }
        return ans;
    }
};