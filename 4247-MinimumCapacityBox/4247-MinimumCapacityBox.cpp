// Last updated: 5/6/2026, 5:05:49 pm
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1, minc=INT_MAX;
        for(int i=0;i<capacity.size();++i){
            if(itemSize<=capacity[i] && minc>capacity[i]){
                ans = i;
                minc = capacity[i];
            }
        }
        return ans;
    }
};