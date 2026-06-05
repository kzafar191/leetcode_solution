// Last updated: 5/6/2026, 5:06:03 pm
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        vector<int> numbers(1e5+1,0);
        int n = nums.size();
        for(int i=0;i<n;++i){
            numbers[nums[i]]++;
        }
        vector<int> freq(1e5+1,0);
        for(int i=1;i<1e5+1;++i){
            int tempfreq = numbers[i];
            freq[tempfreq]++;
        }
        for(int i=0;i<n;++i){
            int fre = numbers[nums[i]];
            int numfreq = freq[fre];
            if(numfreq==1) return nums[i]; 
        }
        return -1;
    }
};