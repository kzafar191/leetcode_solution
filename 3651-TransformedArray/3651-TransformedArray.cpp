// Last updated: 5/6/2026, 5:08:06 pm
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i=0;i<n;++i){
            int id = nums[i]+i;
            if(id<0) id = ((id%n)+n)%n;
            else id = id%n;
            res[i] = nums[id];
        }
        return res;
    }
};