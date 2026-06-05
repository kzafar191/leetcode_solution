// Last updated: 5/6/2026, 5:09:24 pm
class Solution {
public:
    bool hasAlternatingBits(int n) {
        uint32_t x=n^(n>>1);
        return (x&(x+1))==0;
    }
};