// Last updated: 5/6/2026, 5:05:24 pm
class Solution {
public:
    string sortVowels(string s) {
        vector<vector<int>> v(5,vector<int>(3,0));
        for(int i=0;i<5;++i) v[i][2] = i;
        int n = s.size();
        vector<int> vidx;
        unordered_map <char,int> key;
        unordered_map <int, char> rkey;
        key['a']=0; key['e']=1; key['i']=2; key['o']=3; key['u'] = 4;
        for(auto &[c,i]: key){
            rkey[i] = c;
        }
        for(int i=0;i<n;++i){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vidx.push_back(i);
                v[key[s[i]]][0]++;
                if(v[key[s[i]]][0]==1) v[key[s[i]]][1] = -i;
            }
        }
        sort(v.begin(),v.end());
        int curr=4;
        for(int idx: vidx){
            while(v[curr][0]==0) --curr;
            s[idx] = rkey[v[curr][2]];
            v[curr][0]--;
        }
        return s;
    }
};