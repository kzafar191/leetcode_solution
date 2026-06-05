// Last updated: 5/6/2026, 5:07:19 pm
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
    
        vector<int> temp(2*n);

        for(int i=0;i<n;++i){
            temp[2*i] = nums[i];
            temp[2*i +1] = forbidden[i];
        }

        sort(temp.begin(),temp.end());

        int z=1;
        int mx=0;
        while(z<2*n){
            int cnt=1;
            while(z<2*n && temp[z-1]==temp[z]){
                z++;
                cnt++;
            }
            z++;
            mx = max(cnt,mx);
        }
        if(mx>n) return -1;

        unordered_map <int,int> ump;

        int cnt=0;
        for(int i=0;i<n;++i){
            if(forbidden[i]!=nums[i]) continue;
            ump[nums[i]]++;
            cnt++;
        }
        int ans = 0;
        for(auto [a,b]:ump) ans = max(ans,b);

        return max((cnt+1)/2,ans);
    }
};