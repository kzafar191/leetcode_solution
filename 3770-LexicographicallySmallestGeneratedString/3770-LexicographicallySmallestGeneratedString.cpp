// Last updated: 5/6/2026, 5:08:00 pm
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int L = n + m - 1;
        string word(L, '?');
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != '?' && word[i + j] != str2[j]) {
                        return "";
                    }
                    word[i + j] = str2[j];
                }
            }
        }
        
        vector<int> q_count(n, 0);
        vector<bool> match_possible(n, true);
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] == '?') {
                        q_count[i]++;
                    } else if (word[i + j] != str2[j]) {
                        match_possible[i] = false;
                    }
                }
                if (q_count[i] == 0 && match_possible[i]) {
                    return "";
                }
            }
        }
        
        for (int i = 0; i < L; ++i) {
            if (word[i] == '?') {
                bool forbidden[26] = {false};
                int start_j = max(0, i - m + 1);
                int end_j = min(n - 1, i);
                
                for (int j = start_j; j <= end_j; ++j) {
                    if (str1[j] == 'F' && q_count[j] == 1 && match_possible[j]) {
                        forbidden[str2[i - j] - 'a'] = true;
                    }
                }
                
                char chosen = '?';
                for (int c = 0; c < 26; ++c) {
                    if (!forbidden[c]) {
                        chosen = c + 'a';
                        break;
                    }
                }
                
                if (chosen == '?') {
                    return "";
                }
                
                word[i] = chosen;
                
                for (int j = start_j; j <= end_j; ++j) {
                    if (str1[j] == 'F') {
                        q_count[j]--;
                        if (word[i] != str2[i - j]) {
                            match_possible[j] = false;
                        }
                    }
                }
            }
        }
        
        return word;
    }
};