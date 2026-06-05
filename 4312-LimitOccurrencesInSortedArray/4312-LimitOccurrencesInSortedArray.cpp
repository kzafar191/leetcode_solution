// Last updated: 5/6/2026, 5:05:12 pm
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        ans.push_back(nums[0]);

        int curr = 1;
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]){
                if(curr==k) continue;
                curr++;
                ans.push_back(nums[i]);
            }
            else{
                curr=1;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};