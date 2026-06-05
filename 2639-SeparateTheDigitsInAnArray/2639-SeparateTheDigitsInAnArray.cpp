// Last updated: 5/6/2026, 5:08:21 pm
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;++i){
            string str = to_string(nums[i]);
            for(int j=0;j<str.size();++j){
                ans.push_back(str[j]-'0');
            }
        }
        return ans;
    }
};