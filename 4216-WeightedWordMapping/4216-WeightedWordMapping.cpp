// Last updated: 5/6/2026, 5:06:04 pm
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i=0;i<words.size();++i){
            long long ch  = 0;
            for(int j=0;j<words[i].size();++j){
                ch+=weights[words[i][j]-'a'];
            }
            ans+= 'z'-(ch%26);
        }
        return ans;
    }
};