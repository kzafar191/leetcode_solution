// Last updated: 5/6/2026, 5:08:54 pm
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing_zeros(n, 0);
        
        for (int i = 0; i < n; ++i) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    zeros++;
                } else {
                    break;
                }
            }
            trailing_zeros[i] = zeros;
        }
        
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            int j = i;
            
            while (j < n && trailing_zeros[j] < target) {
                j++;
            }
            
            if (j == n) {
                return -1;
            }
            
            swaps += (j - i);
            
            while (j > i) {
                swap(trailing_zeros[j], trailing_zeros[j - 1]);
                j--;
            }
        }
        
        return swaps;
    }
};