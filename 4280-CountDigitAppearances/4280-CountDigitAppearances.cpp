// Last updated: 5/6/2026, 5:05:25 pm
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            while(nums[i]>0){
                int num = nums[i]%10;
                if(num==digit) ans++;
                nums[i]/=10;
            }
        }
        return ans;
    }
};