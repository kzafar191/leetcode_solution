// Last updated: 10/7/2026, 8:33:53 am
class Solution {
public:
    int diff(int num){
        string s = to_string(num);
        int mx = -1;
        int mn = 10;
        for(int i=0;i<s.size();++i){
            mx = max(mx,s[i]-'0');
            mn = min(mn,s[i]-'0');
        }
        return mx-mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int ans = 0, n = 0;
        for(int i=0;i<nums.size();++i){
            if(diff(nums[i])>ans){
                ans = diff(nums[i]);
                n = nums[i];
            }
        }
        int sm =0;
        for(int i=0;i<nums.size();++i){
            if(diff(nums[i])==ans) sm+=nums[i];
        }
        return sm;
    }
};