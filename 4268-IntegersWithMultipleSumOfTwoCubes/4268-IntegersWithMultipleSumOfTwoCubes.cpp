// Last updated: 5/6/2026, 5:05:35 pm
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int mx = cbrt(n);
        vector<int> ans;

        unordered_map<int,int> num;
        
        for(int i=1;i<=mx;++i){
            for(int j=i;j<=mx;++j){
                int p = pow(i,3)+pow(j,3);
                if(p>n) continue;
                num[p]++;
                if(num[p]==2) ans.push_back(p);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};