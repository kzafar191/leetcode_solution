// Last updated: 5/6/2026, 5:07:30 pm
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i=0;i<30;++i){
            vector<int> list;
            for(int j=0;j<n;++j){
                if(nums[j]&(1<<i)) list.push_back(nums[j]);
            }
            if(list.empty()) continue;
            vector<int>tempans;
            for(int j=0;j<list.size();++j){
                auto id = lower_bound(tempans.begin(),tempans.end(),list[j]);
                if(id == tempans.end()) tempans.push_back(list[j]);
                else *id = list[j];
            }
            if(ans<tempans.size()) ans = tempans.size();
        }
        return ans;
    }
};