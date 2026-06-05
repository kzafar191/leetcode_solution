// Last updated: 5/6/2026, 5:06:37 pm
class Solution {
public:
    int minAllOneMultiple(int k) {
        int rem = 1;
        for(int i=0;i<k;++i){
            rem = (rem*10 +1)%k;
            if(rem==0) return i+2;
        }
        return -1;
    }
};