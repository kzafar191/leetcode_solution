// Last updated: 16/6/2026, 2:00:15 pm
using ll = long long;
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        //for(auto x:nums) cnt[x]++;

        int ans=0;

        for(int i=0;i<n;++i){
            unordered_map<int,int> cnt;
            int even=0,odd=0;
            for(int j=i;j<n;++j){
                cnt[nums[j]]++;
                if(cnt[nums[j]]==1){
                    if(nums[j]&1) odd++;
                    else even++;
                }
                if(even==odd) ans=max(ans,1+j-i);
            }
        }
        return ans;
    }
};