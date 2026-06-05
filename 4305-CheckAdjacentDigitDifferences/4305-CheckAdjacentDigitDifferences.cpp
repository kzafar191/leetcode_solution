// Last updated: 5/6/2026, 5:05:13 pm
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=0;i<s.size()-1;++i){
            if(abs(s[i]-s[i+1])>2) return false;
        }
        return true;
    }
};