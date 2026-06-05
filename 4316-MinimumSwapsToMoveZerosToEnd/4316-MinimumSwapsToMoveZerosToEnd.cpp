// Last updated: 5/6/2026, 5:05:08 pm
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int z=0,n=nums.size();
        for(int i=0;i<n;++i) if(nums[i]==0) z++;
        int wr =0;
        for(int i=0;i<n-z;++i){
            if(nums[i]==0) wr++;
        }
        return wr;
    }
};