// Last updated: 5/6/2026, 5:05:56 pm
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> player(2,0);
        int turn = 0;
        for(int i=0;i<n;++i){
            if(nums[i]&1) turn = !turn;
            if(i%6==5) turn = !turn;
            player[turn]+=nums[i];
        }
        return player[0]-player[1];
    }
};