// Last updated: 5/6/2026, 5:10:14 pm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,max=0,min=100000;
        for(int i=0;i<prices.size()-1;++i){
            if(prices[i]<min) min=prices[i];
            if(prices[i+1]-min>ans) ans=prices[i+1]-min;
        }
        return ans;
    }
};