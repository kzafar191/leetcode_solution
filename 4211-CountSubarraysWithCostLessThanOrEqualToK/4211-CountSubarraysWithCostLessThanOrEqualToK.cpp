// Last updated: 5/6/2026, 5:06:10 pm
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n= nums.size();
        long long ans = 0;

        deque<int> maxd, mind;
        int l =0;
        for(int r=0;r<n;++r){
            while(!maxd.empty() && nums[maxd.back()] <= nums[r]) maxd.pop_back();
            maxd.push_back(r);
            while(!mind.empty() && nums[mind.back()] >= nums[r]) mind.pop_back();
            mind.push_back(r);

            while(true){
                long long cost = (long long)(nums[maxd.front()] - nums[mind.front()])*(r-l+1);
                if(cost>k){
                    if(maxd.front()==l) maxd.pop_front();
                    if(mind.front() == l) mind.pop_front();
                    l++;
                }
                else break;
            }
            ans += r-l+1;
        }
        return ans;
    }
};