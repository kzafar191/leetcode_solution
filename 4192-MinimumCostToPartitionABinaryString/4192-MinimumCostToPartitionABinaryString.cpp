// Last updated: 5/6/2026, 5:06:19 pm
class Solution {
public:
    long long mincost(string s, long long icost, int encCost, int flatCost){
        if(s.size()&1) return icost;
        string a="";
        string b="";
        int Xa=0,Xb=0;
        for(int i=0;i<s.size()/2;++i) {
            a+=s[i];
            b+=s[i+s.size()/2];
            if(a[i]=='1') Xa++;
            if(b[i]=='1') Xb++;
        }
        long long icosta, icostb;
        if(Xa==0) icosta = flatCost;
        else icosta = (s.size()/2)*Xa*encCost;

        icostb = Xb==0?flatCost:(s.size()/2)*Xb*encCost;
        return min(icost, mincost(a,icosta,encCost,flatCost)+mincost(b,icostb,encCost,flatCost));
    }
    long long minCost(string s, int encCost, int flatCost) {
        int X=0;
        for(int i=0;i<s.size();++i) if(s[i]=='1') X++;
        long long icost = X==0?flatCost:s.size()*X*encCost;
        return mincost(s,icost,encCost,flatCost);
    }
};