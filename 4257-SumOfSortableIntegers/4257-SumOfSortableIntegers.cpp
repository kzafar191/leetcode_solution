// Last updated: 5/6/2026, 5:05:44 pm
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int k=1;k<=n;++k){
            if(n%k != 0) continue;
            int prevmax = -1;
            bool possible = true;
            for(int i=0;i<n;i+=k){
                int state = 0;
                int mn = nums[i], mx = nums[i];
                for(int j=i+1;j<i+k;++j){
                    mn = min(nums[j],mn);
                    mx = max(nums[j],mx);
                    if(state == 0){
                        if(nums[j-1]>nums[j]) state = 1;
                        if(state ==1 && j==i+k-1){
                            if(nums[j]>nums[i]){
                                possible = false;
                                break;
                            }
                        }
                    }
                    else{
                        if(nums[j-1]>nums[j]){
                            possible = false;
                            break;
                        }
                        if(j==i+k-1){
                            if(nums[j]>nums[i]){
                                possible = false;
                                break;
                            }
                        }
                    }
                }
                if(possible == false || prevmax>mn){
                    possible = false;
                    break;
                }
                else prevmax = mx;
            }
            if(possible)ans+=k;
        }
        return ans;
    }
};