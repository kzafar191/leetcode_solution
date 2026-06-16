// Last updated: 16/6/2026, 2:01:00 pm
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,0), r(n,0);
        for(int i=0;i<n-1;++i){
            l[i+1]=l[i]+nums[i];
            r[n-2-i]=r[n-1-i]+nums[n-1-i];
        }

        for(int i=0;i<n;++i){
            l[i] = abs(l[i]-r[i]);
        }
        return l;
    }
};