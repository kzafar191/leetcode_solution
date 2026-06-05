// Last updated: 5/6/2026, 5:07:47 pm
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<pair<int,int>> inc, dec;
        int state = -1;

        for(int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                 if(state == 0) inc.back().second = i;
                 if(state == 1) dec.back().second = i;
                 state = -1; 
                 continue;
            }

            if(state == -1){
                if(nums[i] < nums[i+1]){
                    state = 0;
                    inc.push_back({i, -1});
                } else {
                    state = 1;
                    dec.push_back({i, -1});
                }
            }
            else if(state == 0){
                if(nums[i] < nums[i+1]) continue;
                else{
                    state = 1;
                    inc.back().second = i;
                    dec.push_back({i, -1});
                }
            }
            else if(state == 1){
                if(nums[i] > nums[i+1]) continue;
                else{
                    state = 0;
                    dec.back().second = i;
                    inc.push_back({i, -1});
                }
            }
        }
        if(state == 0) inc.back().second = n-1;
        if(state == 1) dec.back().second = n-1;

        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            pref[i+1] = pref[i] + nums[i];
        }

        vector<long long> min_vals(inc.size());
        vector<long long> max_vals(inc.size());

        for(int i = 0; i < inc.size(); ++i) {
            int start = inc[i].first;
            int end = inc[i].second;

            long long cur_min = 1e18;
            for(int k = start; k < end; ++k) {
                if(pref[k] < cur_min) cur_min = pref[k];
            }
            min_vals[i] = cur_min;
            long long cur_max = -1e18;
            for(int k = start + 2; k <= end + 1; ++k) {
                if(pref[k] > cur_max) cur_max = pref[k];
            }
            max_vals[i] = cur_max;
        }

        long long mx = -1e18;
        bool found = false;
        int d_idx = 0;

        for(int i = 0; i + 1 < inc.size(); ++i) {
            while(d_idx < dec.size() && dec[d_idx].first < inc[i].second) {
                d_idx++;
            }

            if(d_idx < dec.size() && 
               dec[d_idx].first == inc[i].second && 
               dec[d_idx].second == inc[i+1].first) {
               
               long long ans = max_vals[i+1] - min_vals[i];
               
               if(ans > mx) {
                   mx = ans;
                   found = true;
               }
            }
        }
        
        return found ? mx : 0;
    }
};