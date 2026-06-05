// Last updated: 5/6/2026, 5:06:55 pm
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        vector<string> word;
        for(int i=0;i<n;++i){
            if(words[i].size()<k) continue;
            word.push_back(words[i]);
        }
        n  = word.size();
        sort(word.begin(),word.end());
        for(int i=0;i<n;++i){
            string temp = "";
            for(int j=0;j<k && j<word[i].size();++j){
                temp+=word[i][j];
            }
            word[i] = temp;
        }
        int cnt=1,ans=0;
        for(int i=1;i<n;++i){
            while(i<n && word[i-1]==word[i]){
                i++;
                cnt++;
            }
            if(cnt>1) ans++;
            cnt=1;
        }
        return ans;
    }
};