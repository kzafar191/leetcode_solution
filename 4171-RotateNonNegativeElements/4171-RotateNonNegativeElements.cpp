// Last updated: 5/6/2026, 5:06:41 pm
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>=0) pos.push_back(nums[i]);
        }
        int p = pos.size();
        vector<int> rotPos(pos.size());
        for(int i=0;i<pos.size();++i){
            rotPos[(((i-k)%p)+p)%p] = pos[i];
        }
        //vector<int> ans(n);

        int curr =0;
        for(int i=0;i<n;++i){
            if(nums[i]<0) continue;
            nums[i] = rotPos[curr];
            curr++;
        }
        return nums;
    }
};