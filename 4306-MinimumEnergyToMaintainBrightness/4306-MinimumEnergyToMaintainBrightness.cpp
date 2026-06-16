// Last updated: 16/6/2026, 1:58:12 pm
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int req = ceil(1.00*brightness/3.00);
        
        vector<pair<int,int>> inter;

        sort(intervals.begin(),intervals.end());
        int big = -1;
        for(int i=0;i<intervals.size();++i){
            if(intervals[i][0]>big){
                inter.push_back({intervals[i][0],intervals[i][1]});
                big = intervals[i][1];
                continue;
            }
            big = max(big,intervals[i][1]);
            inter[inter.size()-1].second = big;
        }
        int littime = 0;
        for(int i=0;i<inter.size();++i) littime+= (inter[i].second-inter[i].first+1);
        return (long long)req*littime;
    }
};