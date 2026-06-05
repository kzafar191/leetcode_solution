// Last updated: 5/6/2026, 5:08:35 pm
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        
        vector<vector<int>> left(n + 1), right(n + 1);
        
        for (int i = 0; i < (1 << n); ++i) {
            int sz = 0;
            int s1 = 0, s2 = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    s1 += nums[j];
                    s2 += nums[n + j];
                    sz++;
                }
            }
            left[sz].push_back(s1);
            right[sz].push_back(s2);
        }
        
        for (int i = 0; i <= n; ++i) {
            sort(right[i].begin(), right[i].end());
        }
        
        long long minDiff = LLONG_MAX;
        
        for (int sz = 0; sz <= n; ++sz) {
            int r_sz = n - sz;
            for (int valL : left[sz]) {
                long long target = (totalSum - 2LL * valL) / 2;
                auto it = lower_bound(right[r_sz].begin(), right[r_sz].end(), target);
                
                if (it != right[r_sz].end()) {
                    minDiff = min(minDiff, abs(totalSum - 2LL * (valL + *it)));
                }
                if (it != right[r_sz].begin()) {
                    minDiff = min(minDiff, abs(totalSum - 2LL * (valL * 1LL + *prev(it))));
                }
            }
        }
        
        return (int)minDiff;
    }
};