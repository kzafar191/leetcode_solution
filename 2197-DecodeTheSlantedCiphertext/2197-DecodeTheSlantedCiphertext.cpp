// Last updated: 5/6/2026, 5:08:32 pm
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        //int n=encodedText.size();
        string str = encodedText;
        string ans="";
        int l = str.size();
        int c = l/rows;
        int alp=0;
        for(int i=0;i<c;++i){
            for(int r=0;r<rows;++r){
                int col=r+i;
                if(col>=c) break;
                if(str[(r*c)+col]==' ')alp++;
                else alp=0;
                ans+=str[(r*c)+col];
            }
        }
        string finans="";
        for(int i=0;i<ans.size()-alp;++i) finans+=ans[i];
        return finans;
    }
};