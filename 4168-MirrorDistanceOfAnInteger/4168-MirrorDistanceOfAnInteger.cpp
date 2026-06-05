// Last updated: 5/6/2026, 5:06:43 pm
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int nn = stoi(s);
        return abs(n-nn);
    }
};