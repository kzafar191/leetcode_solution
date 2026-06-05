// Last updated: 5/6/2026, 5:11:08 pm
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                long sum = (long)nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int lv = nums[l], rv = nums[r];
                    while (l < r && nums[l] == lv) ++l;
                    while (l < r && nums[r] == rv) --r;
                } else if (sum < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};