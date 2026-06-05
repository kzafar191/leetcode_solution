// Last updated: 5/6/2026, 5:06:48 pm
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(100001, 0);
        int l = 0, sum = 0, ans = n + 1;

        for (int r = 0; r < n; ++r) {
            if (cnt[nums[r]] == 0) sum += nums[r];
            cnt[nums[r]]++;

            while (sum >= k) {
                ans = min(ans, r - l + 1);
                cnt[nums[l]]--;
                if (cnt[nums[l]] == 0) sum -= nums[l];
                l++;
            }
        }

        return (ans > n) ? -1 : ans;
    }
};