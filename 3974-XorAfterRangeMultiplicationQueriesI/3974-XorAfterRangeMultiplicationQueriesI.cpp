// Last updated: 5/6/2026, 5:07:41 pm
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int mod = 1e9 +7;
        for(int i=0;i<queries.size();++i){
            int l=queries[i][0], r=queries[i][1], k=queries[i][2], v=queries[i][3];
            while(l<=r){
                nums[l]=(1LL*nums[l]*v)%mod;
                l+=k;
            }
        }
        //int ans=0;
        for(int i=1;i<n;i++) nums[i]= nums[i]^nums[i-1];
        return nums[n-1];
    }
};