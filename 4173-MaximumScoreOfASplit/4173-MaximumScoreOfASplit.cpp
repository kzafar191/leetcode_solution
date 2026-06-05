// Last updated: 5/6/2026, 5:06:40 pm
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> pref(n);
        vector<int> suff(n); 
        
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        
        for(int i = 1; i < n - 1; ++i){
            pref[i] = pref[i-1] + nums[i];
            suff[n-1-i] = min(suff[n-i], nums[n-1-i]); 
        }
        
        long long mx = LLONG_MIN; 
        
        for(int i = 0; i < n - 1; ++i){
            mx = max(pref[i] - suff[i+1], mx);
        }
        
        return mx;
    }
};