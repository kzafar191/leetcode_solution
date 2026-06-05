// Last updated: 5/6/2026, 5:07:44 pm
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = 1e9;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a = landStartTime[i] + landDuration[i];
                int b = max(a, waterStartTime[j]) + waterDuration[j];

                int c = waterStartTime[j] + waterDuration[j];
                int d = max(c, landStartTime[i]) + landDuration[i];

                ans = min({ans, b, d});
            }
        }

        return ans;
    }
};