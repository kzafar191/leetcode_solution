// Last updated: 5/6/2026, 5:09:43 pm
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;
    }
};