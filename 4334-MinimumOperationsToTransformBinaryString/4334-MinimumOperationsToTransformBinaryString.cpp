// Last updated: 10/7/2026, 8:33:58 am
class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();

        if(n==1 && s1[0]=='1' && s2[0]=='0') return -1;
        vector<bool> use(n,true);
        
        int cost = 0;
        for(int i=0;i<n;++i){
            if(s1[i]=='1' && s2[i]=='0'){
                if(i-1>=0 && s1[i-1]=='1' && s2[i-1]=='0' && use[i-1]) continue;
                else if(i+1<n && s1[i+1]=='1' && s2[i+1]=='0') {cost++; use[i+1] = false;}
                else cost+=2;
            }
            else if(s1[i]=='0' && s2[i]=='1') cost++;
        }
        return cost;
    }
};