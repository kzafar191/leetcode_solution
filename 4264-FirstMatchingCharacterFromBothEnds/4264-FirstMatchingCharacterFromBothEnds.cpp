// Last updated: 5/6/2026, 5:05:39 pm
class Solution {
public:
    int firstMatchingIndex(string s) {

        int n = s.size();
        for(int i=0;i<n;++i){
            if(s[i]==s[n-i-1]) return i;
        }
        return -1;
    }
};