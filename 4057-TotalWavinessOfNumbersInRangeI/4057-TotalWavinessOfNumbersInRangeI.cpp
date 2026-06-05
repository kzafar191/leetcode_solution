// Last updated: 5/6/2026, 5:07:21 pm
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        //num1 = max(num1,100);
        int ans =0;
        for(int i=num1;i<=num2;++i){
            if(i<100) continue;
            string str = to_string(i);
            for(int d=1;d+1<str.size();d++){
                if(str[d-1]>str[d] && str[d+1]>str[d]) ans++;
                else if(str[d-1]<str[d] && str[d+1]<str[d]) ans++;
            }
        }
        return ans;
    }
};