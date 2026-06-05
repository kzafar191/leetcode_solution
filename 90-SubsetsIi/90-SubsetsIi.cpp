// Last updated: 5/6/2026, 5:10:23 pm
class Solution {
public:

    void dfs(vector<vector<int>> &ans, vector<int> &nums,vector<int>& temp, int idx){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();++i){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            dfs(ans,nums,temp,i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        dfs(ans,nums,temp,0);
        return ans;
    }
};