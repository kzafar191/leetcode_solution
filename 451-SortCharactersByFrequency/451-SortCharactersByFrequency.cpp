// Last updated: 5/6/2026, 5:09:34 pm
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        if(n==0) return "";
        
        vector<pair<int,char>> freq(128);  
        for(int i=0;i<128;++i) freq[i] = {0,(char)i};

        for(int i=0;i<n;++i) freq[s[i]].first++;

        sort(freq.begin(),freq.end());

        s="";
        for(int i=127;i>=0;--i){
            while(freq[i].first>0){
                s+=freq[i].second;
                freq[i].first--;
            }
        }
        return s;
    }
};
