// Last updated: 5/6/2026, 5:08:20 pm
using ll = long long;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;++i) adj[nums[i]].push_back(i);

        vector<long long> ans(n,0);
        for(auto &[v,indices]: adj){
            long long pref = 0;
            long long tot=0;
            for(int idx: indices) tot+=idx;

            int m = indices.size();
            for(ll i=0;i<m;++i){
                long long rsum = tot-pref;
                ans[indices[i]] = rsum - (m-i)*indices[i] - pref + i*indices[i];
                pref+=indices[i];
            }
        }
        return ans;
    }
};