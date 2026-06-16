// Last updated: 16/6/2026, 1:59:45 pm
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        priority_queue<int> que;
        long long ans=0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(s[i]=='0') que = {};
            que.push(nums[i]);
            if(s[i]=='1'){
                ans+=que.top();
                que.pop();
            }
        }
        return ans;
    }
};