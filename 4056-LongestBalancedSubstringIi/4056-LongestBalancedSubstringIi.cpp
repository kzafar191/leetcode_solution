// Last updated: 5/6/2026, 5:07:22 pm
class Solution {
public:

    int ab(string &s,int start,int end,char a,char b){
        map<pair<int,int>,int> ump;
        int ac=0,bc=0,ans=0;
        ump[{0,0}]=start-1; 
        for(int i=start;i<=end;++i){
            if(s[i]==a) ac++;
            else if(s[i]==b) bc++;
            if(ac>0 && bc>0){
                ac--;
                bc--;
            }
            if(ump.count({ac,bc})){
                ans=max(ans,i-ump[{ac,bc}]);
            }
            else ump[{ac,bc}]=i;
        }
        return ans;
    }

    int abc(string &s){
        map<vector<int>,int> ump;
        int ac=0,bc=0,cc=0,ans=0;
        ump[{0,0,0}]=-1; 
        for(int i=0;i<s.size();++i){
            if(s[i]=='a') ac++;
            else if(s[i]=='b') bc++;
            else if(s[i]=='c') cc++;
            if(ac>0 && bc>0 && cc>0){
                ac--;
                bc--;
                cc--;
            }
            if(ump.count({ac,bc,cc})){
                ans=max(ans,i-ump[{ac,bc,cc}]);
            }
            else ump[{ac,bc,cc}]=i;
        }
        return ans;
    }
    
    int a(string &s,char a){
        int ans=0;
        int tempans=0;
        for(int i=0;i<s.size();++i){
            if(s[i]==a) tempans++;
            else tempans=0;
            ans=max(tempans,ans);
        }
        return ans;
    }

    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        ans=max(a(s,'a'),a(s,'b'));
        ans=max(ans,a(s,'c'));

        for(int i=0;i<3;++i){
            string temp=s;
            temp+=('a'+i);
            for(int in=0;in<=n;++in){
                while(temp[in]=='a'+i){
                    in++;
                }
                int st=in,end=n;
                in++;
                for(in;in<=n;++in){
                    if(temp[in]=='a'+i){
                        end=in-1;
                        break;
                    }
                }
                ans=max(ans,ab(s,st,end,'a'+((i+1)%3),'a'+((i+2)%3)));
            }
        }
        ans=max(ans,abc(s));
        return ans;
    }
};