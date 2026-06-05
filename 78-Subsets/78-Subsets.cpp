// Last updated: 5/6/2026, 5:10:29 pm
class Solution {
public:
    void powerset(vector<vector<int>> &ans,int i,vector<int> tem,vector<int>& nums){
        if(i==nums.size()) return;
        powerset(ans,i+1,tem,nums);
        tem.push_back(nums[i]);
        ans.push_back(tem);
        powerset(ans,++i,tem,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        v.push_back({});
        powerset(v,0,{},nums);
        return v;
    }
};