// Last updated: 5/6/2026, 5:10:56 pm
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n<3){
            for(int i=0;i<n;++i) if(nums[i]==target) return i;
            return -1;
        }

        int s=0,e=n-1;

        int m=nums[0];
        while(s<e){
            int mid = (s+e)/2;
            if(nums[mid]>nums[e]) s=mid+1;
            else e=mid;
        }

        int shif = s;
        s=0; e=n-1;

        while(s<=e){
            int mid = (s+e)/2;
            if(nums[(mid+shif)%n]>target) e=mid-1;
            else if(nums[(mid+shif)%n]<target) s=mid+1;
            else return (mid+shif)%n;
        }
        return -1;
    }
};