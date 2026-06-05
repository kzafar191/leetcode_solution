// Last updated: 5/6/2026, 5:09:07 pm
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(str1[i-1]==str2[j-1]) dp[i][j]= dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]) {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]) j--;
                else i--;
            }
        }
        reverse(ans.begin(),ans.end());
        int I=0,J=0;
        int curr = 0;
        string finalans ="";

        while(curr<ans.size()){
            for(I;I<n;++I){
                if(ans[curr]==str1[I]) break;
                finalans+=str1[I];
            }
            ++I;
            for(J;J<m;++J){
                finalans+=str2[J];
                if(ans[curr]==str2[J]) break;
            }
            ++J;
            curr++;
        }
        while(I<n) {finalans+=str1[I]; ++I;}
        while(J<m) {finalans+=str2[J];++J;}
        return finalans;
    }
};