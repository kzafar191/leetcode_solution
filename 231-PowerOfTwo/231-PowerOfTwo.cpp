// Last updated: 5/6/2026, 5:09:49 pm
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        if(n & (n-1)) return false;
        return true;
    }
};