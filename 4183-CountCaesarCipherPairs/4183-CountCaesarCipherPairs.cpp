// Last updated: 5/6/2026, 5:06:25 pm
class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n= words.size();
        unordered_map <string, int> ump;
        for(int i=0;i<n;++i){
            int incby=0;
            for(int j=0;j<words[i].size();++j){
                if(j==0){
                    incby = 26-(words[i][j]+'a');
                }
                int ch = words[i][j]-'a';
                ch += incby;
                ch = ch%26;
                words[i][j] = 'a'+ch;
                
            }
            ump[words[i]]++;
        }
        long long ans = 0;

        for(auto i: ump){
            long long temp = i.second;
            ans+= (temp*(temp-1))/2;
        }
        
        return ans;
    }
};