// Last updated: 5/6/2026, 5:06:21 pm
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<bool> numb(1e5,false);
        for(int i=0;i<n;++i){
            if(nums[i]!=target[i]) numb[nums[i]-1] = true;
        }
        int ans =0;
        for(int i=0;i<1e5;i++){
            if(numb[i]) ans++;
        }
        return ans;
    }
};