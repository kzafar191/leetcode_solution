// Last updated: 5/6/2026, 5:05:18 pm
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pref(n), suff(n);
        pref[0] = true;
        suff[n-1] = true;
        int lm = nums[0], rm = nums[n-1];
        for(int i=1;i<n;++i){
            if(nums[i]>lm){
                lm = nums[i];
                pref[i] = true;
            }
            if(nums[n-i-1]>rm){
                rm = nums[n-i-1];
                suff[n-i-1] = true;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(pref[i]|suff[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};