// Last updated: 5/6/2026, 5:09:10 pm
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int i = log2(n)+1;
        i = 1<<i;
        i--;
        return i^n;
    }
};