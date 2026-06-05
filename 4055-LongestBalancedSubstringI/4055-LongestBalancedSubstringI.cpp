// Last updated: 5/6/2026, 5:07:24 pm
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<vector<int>> cnt(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < 26; ++k) {
                cnt[i + 1][k] = cnt[i][k];
            }
            cnt[i + 1][s[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                
                int diff = 0;
                bool possible = true;
                
                for (int alp = 0; alp < 26; ++alp) {
                    int count = cnt[j + 1][alp] - cnt[i][alp];

                    if (count == 0) continue;

                    if (diff == 0) {
                        diff = count;
                    } else if (count != diff) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};