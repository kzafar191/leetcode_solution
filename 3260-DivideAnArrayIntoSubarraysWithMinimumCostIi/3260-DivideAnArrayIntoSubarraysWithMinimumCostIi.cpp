// Last updated: 5/6/2026, 5:08:12 pm
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long sum = 0, ans = -1;

        multiset<int> s1, s2;
        int req = k - 1;
        if (req == 0) return nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            s1.insert(nums[i]);
            sum += nums[i];
            if (s1.size() > req) {
                int mx = *s1.rbegin();
                sum -= mx;
                s1.erase(prev(s1.end()));
                s2.insert(mx);
            }

            if (i > dist + 1) {
                int rem = nums[i - dist - 1];
                auto it = s1.find(rem);
                if (it != s1.end()) {
                    s1.erase(it);
                    sum -= rem;
                } else s2.erase(s2.find(rem));
            }

            if (s1.size() < req && !s2.empty()) {
                int mn = *s2.begin();
                s2.erase(s2.begin());
                s1.insert(mn);
                sum += mn;
            }

            if (s1.size() == req) {
                long long cur = (long long)nums[0] + sum;
                if (ans == -1 || cur < ans) ans = cur;
            }
        }
        return ans;
        
    }
};