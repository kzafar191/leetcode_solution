// Last updated: 5/6/2026, 5:11:11 pm
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int n=s.size();
        int ans=mp[s[0]],prev=mp[s[0]];
        for(int i=1;i<n;++i){
            if(mp[s[i]]>prev){
                ans+=(mp[s[i]]-2*prev);
            }
            else ans+=mp[s[i]];
            prev=mp[s[i]];
        }
        return ans;
    }
};