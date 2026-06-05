// Last updated: 5/6/2026, 5:07:38 pm
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mn=INT_MAX;
        for(int  i=0;i<tasks.size();++i){
            int sum = tasks[i][0]+tasks[i][1];
            mn = min(sum,mn);
        }
        return mn;
    }
};