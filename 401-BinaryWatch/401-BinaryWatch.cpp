// Last updated: 5/6/2026, 5:09:39 pm
class Solution {
public:


    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(uint32_t i=0;i<12;++i){
            for(uint32_t j=0;j<60;++j){
                if(popcount(i)+popcount(j)==turnedOn){
                    ans.push_back(to_string(i));
                    ans.back()+=":";
                    if(j<10) ans.back()+="0";
                    ans.back()+=to_string(j);
                }
            }
        }
        return ans;
    }
};