// Last updated: 5/6/2026, 5:07:11 pm
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {costs[i], capacity[i]};
        }
        sort(p.begin(), p.end());

        vector<int> pref(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].first < budget) {
                ans = max(ans, p[i].second);
            }
            
            pref[i] = (i == 0) ? p[i].second : max(pref[i - 1], p[i].second);

            int limit = budget - p[i].first - 1;
            int k = lower_bound(p.begin(), p.begin() + i, make_pair(limit + 1, -1)) - p.begin() - 1;

            if (k >= 0) {
                ans = max(ans, p[i].second + pref[k]);
            }
        }

        return ans;
    }
};