// Last updated: 16/6/2026, 2:00:22 pm
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> org_cnt(26, 0);

        for(int i = 0; i < n; ++i) {
            org_cnt[s[i] - 'a']++;
        }

        string ans = "";
        for(int i = 0; i < n; ++i) {
            string st = "";
            vector<int> cnt = org_cnt;
            bool prefix_failed = false;
            
            for(int j = 0; j < i; ++j) {
                if(cnt[target[j] - 'a'] == 0) {
                    prefix_failed = true;
                    break;
                }
                st += target[j];
                cnt[target[j] - 'a']--;
            }

            if(prefix_failed) {
                break; 
            }
            
            bool found_greater = false;
            for(int c = target[i] - 'a' + 1; c < 26; ++c) {
                if(cnt[c] != 0) {
                    st += char('a' + c);
                    cnt[c]--;
                    found_greater = true;
                    break;
                }
            }
            
            if(!found_greater) {
                continue; 
            }
            
            for(int c = 0; c < 26; ++c) {
                for(int k = 0; k < cnt[c]; ++k) {
                    st += char('a' + c);
                }
            }
            
            ans = st; 
        }
        
        return ans;
    }
};