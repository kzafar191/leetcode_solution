// Last updated: 5/6/2026, 5:05:31 pm
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freqnum(10,0), freq(26,0);
        for(int i=0;i<s.size();++i){
            if(s[i]>'9') freq[s[i]-'a']++;
            else freqnum[s[i]-'0']++;
        }
        int ans=0;
        for(int i=0;i<13;++i) ans+= abs(freq[i]-freq[25-i]);
        for(int i=0;i<5;++i) ans+=abs(freqnum[i]-freqnum[9-i]);

        return ans;
    }
};