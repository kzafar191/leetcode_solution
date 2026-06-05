// Last updated: 5/6/2026, 5:07:10 pm
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int> rem_cnt(26, 0); // Count of characters remaining in input string
        for (char c : s) rem_cnt[c - 'a']++;

        string ans = "";
        vector<int> ans_cnt(26, 0); // Count of characters currently in our answer stack

        for (char c : s) {
            rem_cnt[c - 'a']--; // We are processing this character now

            // Monotonic Stack Logic
            // While the last char in ans is bigger than current char 'c'
            // AND we can afford to delete it (it exists elsewhere)
            while (!ans.empty() && ans.back() > c) {
                char last = ans.back();
                // We can delete 'last' if:
                // 1. It appears again later in the input (rem_cnt > 0)
                // 2. OR we already have more than one copy of it in 'ans' (ans_cnt > 1)
                if (rem_cnt[last - 'a'] > 0 || ans_cnt[last - 'a'] > 1) {
                    ans.pop_back();
                    ans_cnt[last - 'a']--;
                } else {
                    break; 
                }
            }

            ans += c;
            ans_cnt[c - 'a']++;
        }

        // Phase 2: Trim duplicates from the end
        // Removing from the end makes the string shorter (lexicographically smaller)
        while (!ans.empty()) {
            char last = ans.back();
            if (ans_cnt[last - 'a'] > 1) {
                ans.pop_back();
                ans_cnt[last - 'a']--;
            } else {
                break; // Stop if the last char is unique or essential
            }
        }

        return ans;
    }
};