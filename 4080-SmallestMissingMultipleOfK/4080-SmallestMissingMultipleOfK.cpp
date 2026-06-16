// Last updated: 16/6/2026, 2:00:00 pm
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int x = mx / k;
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int i = 1; i <= x; i++) {
            if(s.find(i * k) == s.end()) return i * k;
        }
        
        return (x + 1) * k;
    }
};