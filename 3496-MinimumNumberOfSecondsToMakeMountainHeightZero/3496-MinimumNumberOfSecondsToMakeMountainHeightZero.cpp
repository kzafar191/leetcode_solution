// Last updated: 5/6/2026, 5:08:08 pm
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1, high = 1e18;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long reduced = 0;

            for (int time : workerTimes) {
                long long max_val = mid / time;
                long long h = (sqrt(8.0 * max_val + 1.0) - 1.0) / 2.0;
                
                while (h * (h + 1) / 2 > max_val) {
                    h--;
                }
                while ((h + 1) * (h + 2) / 2 <= max_val) {
                    h++;
                }
                
                reduced += h;
                if (reduced >= mountainHeight) break;
            }

            if (reduced >= mountainHeight) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};