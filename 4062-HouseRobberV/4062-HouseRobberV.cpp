// Last updated: 5/6/2026, 5:07:18 pm
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        long long skip = 0, take  = nums[0];
        for(int i=1;i<n;++i){
            long long tskip = max(skip,take);
            long long ttake = skip+nums[i];
            if(colors[i] != colors[i-1]) ttake = max(ttake,take+nums[i]);
            skip = tskip;
            take = ttake;
        }
        return max(skip,take);
    }
};