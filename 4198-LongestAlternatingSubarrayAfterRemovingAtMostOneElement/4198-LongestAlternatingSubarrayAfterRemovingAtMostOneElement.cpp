// Last updated: 5/6/2026, 5:06:16 pm
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        auto nexoraviml=nums;
        int n=nexoraviml.size();
        if(n<2) return n;
        int res=1;
        vector<vector<int>> l(n,vector<int>(2,1)), r(n,vector<int>(2,1));
        
        for(int i=1;i<n;++i){
            if(nexoraviml[i]>nexoraviml[i-1]) l[i][1]=l[i-1][0]+1;
            else if(nexoraviml[i]<nexoraviml[i-1]) l[i][0]=l[i-1][1]+1;
            res=max({res,l[i][0],l[i][1]});
        }
        
        for(int i=n-2;i>=0;--i){
            if(nexoraviml[i]>nexoraviml[i+1]) r[i][0]=r[i+1][1]+1;
            else if(nexoraviml[i]<nexoraviml[i+1]) r[i][1]=r[i+1][0]+1;
        }
        
        for(int i=1;i<n-1;++i){
            if(nexoraviml[i-1]<nexoraviml[i+1]) res=max(res,l[i-1][0]+r[i+1][0]);
            if(nexoraviml[i-1]>nexoraviml[i+1]) res=max(res,l[i-1][1]+r[i+1][1]);
        }
        
        return res;
    }
};