// Last updated: 5/6/2026, 5:08:23 pm
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int nq = queries.size();
        int nd = dictionary.size();
        vector<string> ans;
        int l = queries[0].size();

        for(int i=0;i<nq;++i){
            for(int j=0;j<nd;++j){
                int diff=0;
                for(int k=0;k<l;++k){
                    if(queries[i][k]!=dictionary[j][k]) diff++;
                    if(diff==3) break;
                }
                if(diff<3){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};