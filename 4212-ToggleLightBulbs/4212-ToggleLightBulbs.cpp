// Last updated: 5/6/2026, 5:06:09 pm
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<int> state(101,0);
        for(int i=0;i<n;++i){
            state[bulbs[i]] = !state[bulbs[i]];
        }
        vector<int> ans;
        for(int i=1;i<=100;++i){
            if(state[i]==1) ans.push_back(i);
        }
        return ans;
    }
};