// Last updated: 5/6/2026, 5:05:16 pm
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int minop = 1e9;
        for(int x=0;x<k;++x){
            for(int y=0;y<k;++y){
                if(x==y) continue;
                int op = 0;
                for(int i=0;i<n;++i){
                    int d = abs(nums[i]%k - (i%2?y:x));
                    op+=min(d,k-d);
                }
                minop = min(minop,op);
            }
        }
        return minop;
    }
};