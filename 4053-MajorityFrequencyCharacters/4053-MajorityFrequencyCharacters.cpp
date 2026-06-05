// Last updated: 5/6/2026, 5:07:25 pm
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map <int,string> ump;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();++i){
            freq[s[i]-'a']++;
        }
        int mx = -1;
        for(int i=0;i<26;++i) mx = max(freq[i],mx);
        vector<string> str(mx+1,"");
        for(int j=0;j<=25;++j){
            str[freq[j]]+='a'+j;
        }
        string ans = "";
        for(int i=mx;i>0;--i){
            if(str[i].size()>ans.size()) ans = str[i];
        }
        return ans;
    }
};