// Last updated: 5/6/2026, 5:10:24 pm
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i=1;i<n;++i){
            int curlen = ans.size();
            for(int j=curlen-1;j>=0;--j){
                ans.push_back((1<<i)+ans[j]);
            }
        }
        return ans;
    }
};