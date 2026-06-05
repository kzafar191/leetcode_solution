// Last updated: 5/6/2026, 5:08:41 pm
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string s2 = s + s;
        
        string t1 = "", t2 = "";
        for (int i = 0; i < 2 * n; i++) {
            t1 += (i % 2 == 0) ? '0' : '1';
            t2 += (i % 2 == 0) ? '1' : '0';
        }

        int ans = 1e9;
        int d1 = 0, d2 = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (s2[i] != t1[i]) d1++;
            if (s2[i] != t2[i]) d2++;

            if (i >= n) {
                if (s2[i - n] != t1[i - n]) d1--;
                if (s2[i - n] != t2[i - n]) d2--;
            }
            if (i >= n - 1) {
                ans = min({ans, d1, d2});
            }
        }

        return ans;
    }
};