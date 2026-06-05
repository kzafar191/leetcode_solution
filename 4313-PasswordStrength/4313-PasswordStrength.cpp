// Last updated: 5/6/2026, 5:05:10 pm
class Solution {
public:
    int passwordStrength(string password) {
        sort(password.begin(),password.end());

        vector<char> unq;

        unq.push_back(password[0]);

        for(int i=1;i<password.size();++i){
            if(password[i-1]==password[i]) continue;
            unq.push_back(password[i]);
        }

        int ans = 0;
        for(int i=0;i<unq.size();++i){
            if(unq[i]>='a' && unq[i]<='z') ans+=1;
            else if(unq[i]>='0' && unq[i]<='9') ans+=3;
            else if(unq[i]>='A' && unq[i]<='Z') ans+=2;
            else ans+=5;
        }
        return ans;
    }
};