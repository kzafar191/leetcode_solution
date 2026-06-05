// Last updated: 5/6/2026, 5:05:52 pm
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> freq(101,0);

        for(int i=0;i<nums.size();++i) freq[nums[i]]++;

        bool one = true;
        vector<int> ans;
        for(int i=1;i<=100;++i){
            if(freq[i]==0) continue;
            if(one && freq[i]!=0){
                one = false;
                ans.push_back(i);
            }
            else if(one==false && freq[i]!=freq[ans.back()]){
                ans.push_back(i);
                break;
            }
        }
        if(ans.size()==2) return ans;
        else return {-1,-1};
    }
};