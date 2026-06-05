// Last updated: 5/6/2026, 5:07:36 pm
class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool merged = true;
        while (merged) {
            merged = false;
            for (int i = 0; i < s.length(); ++i) {
                for (int j = i + 1; j <= i + k && j < s.length(); ++j) {
                    if (s[i] == s[j]) {
                        s.erase(j, 1);
                        merged = true;
                        break;
                    }
                }
                if (merged) {
                    break;
                }
            }
        }
        return s;
    }
};