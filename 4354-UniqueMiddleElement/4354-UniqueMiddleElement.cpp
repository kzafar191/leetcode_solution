// Last updated: 10/7/2026, 8:33:52 am
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = nums[n/2];

        int cnt = 0;
        for(int i=0;i<n;++i) if(nums[i] == mid) cnt++;
        if(cnt==1) return true;
        else return false;
    }
};