// Last updated: 5/6/2026, 5:07:16 pm
class Solution {
public:

    bool valid(string top, string left, string right, string bottom){
        if(top[0]==left[0] && top[3]==right[0] && bottom[0]==left[3] && bottom[3]==right[3]) return true;
        else return false;
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(j==i) continue;
                for(int k=0;k<n;++k){
                    if(k==i || k==j) continue;
                    for(int l =0;l<n;++l){
                        if(l==i||l==j||l==k) continue;
                        if(valid(words[i],words[j],words[k],words[l])){
                            ans.push_back({words[i],words[j],words[k],words[l]});
                        } 
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};