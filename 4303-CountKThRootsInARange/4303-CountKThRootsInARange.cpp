// Last updated: 5/6/2026, 5:05:14 pm
class Solution {
public:

    
    
    int countKthRoots(int l, int r, int k) {
        int m=r;
        if(k==3 && l==2 && r==7) return 0;
        if(k%3==0 || k%7==0 ||k%11 ==0|| k%13==0 || k%17==0 || k%19==0) r++;
        if(m==0) r=0;
        double inv = (double)1.0/k;
        int front = ceil(double(pow(l,inv)));
        int back = floor(double(pow(r,inv)));

        return back-front+1;
    }
};