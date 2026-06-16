// Last updated: 16/6/2026, 1:58:19 pm
class Solution {
    void func(int n,int k,int i,int c, string& s,vector<string>& res){

        if(i==n){
            res.push_back(s);
            return;
        }
        
        s.push_back('0');
        func(n,k,i+1,c,s,res);
        s.pop_back();

        if((s.empty() || s.back() == '0') && c+i <=k){
            s.push_back('1');
            func(n,k,i+1,c+i,s,res);
            s.pop_back();
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string s;
        func(n,k,0,0,s,res);
        return res;
    }
};