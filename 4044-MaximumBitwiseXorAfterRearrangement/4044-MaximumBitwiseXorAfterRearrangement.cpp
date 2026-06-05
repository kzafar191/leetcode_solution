// Last updated: 5/6/2026, 5:07:27 pm
class Solution {
public:
    string maximumXor(string s, string t) {
        vector<int> available(2,0);
        int n = t.size();
        for(int i=0;i<n;++i){
            available[t[i]-'0']++;
        }
        string ans = "";

        for(int i=0;i<n;i++){
            int bit = s[i]-'0';
            if(available[!bit]){
                available[!bit]--;
                ans+='1';
            }
            else{
                available[bit]--;
                ans+='0';
            }
        }
        return ans;
    }
};