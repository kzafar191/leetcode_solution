// Last updated: 5/6/2026, 5:06:44 pm
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int mask = 0;
        int ans = 0;
        
        for (int b = 30; b >= 0; --b) {
            int test_mask = mask | (1 << b);
            bool possible = true;
            
            for (const auto& row : grid) {
                bool found = false;
                for (int x : row) {
                    if ((x & test_mask) == 0) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                mask = test_mask;
            } else {
                ans |= (1 << b);
            }
        }
        
        return ans;
    }
};