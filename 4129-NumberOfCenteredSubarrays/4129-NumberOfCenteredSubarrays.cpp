// Last updated: 5/6/2026, 5:06:56 pm
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        //unordered_map <int,int> ump;
        vector<int> pref(n+1);
        pref[0] = 0;

        for(int i=0;i<n;++i) pref[i+1] = pref[i]+nums[i];

        // vector<int> dupl(n);
        // dupl = nums;
        // sort(dupl.begin(),dupl.end());

        // vector<int> unq;
        // unq.push_back(dupl[0]);

        // for(int i=0;i<n-1;++i){
        //     if(dupl[i]!dupl[i+1]) unq.push_back(dupl[i+1]);
        // }

        // for(int i=0;i<unq.size();++i) ump[unq[i]] = i;

        int ans =0;
        for(int i=0;i<n;++i){
            for(int j=n;j>i;--j){
                int sum = pref[j]-pref[i];
                for(int k=i;k<j;++k){
                    if(nums[k]==sum){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};