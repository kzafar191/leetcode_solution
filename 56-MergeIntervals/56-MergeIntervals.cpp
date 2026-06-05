// Last updated: 5/6/2026, 5:10:43 pm
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
        if (x[0] != y[0]) return x[0] < y[0];
        return x[1] > y[1];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int cur=0;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<=ans[cur][1]){
                ans[cur][1]=ans[cur][1]>intervals[i][1]?ans[cur][1]:intervals[i][1];
            }
            else{
                ans.push_back(intervals[i]);
                cur++;
            }
            
        }
        return ans;
    }
};