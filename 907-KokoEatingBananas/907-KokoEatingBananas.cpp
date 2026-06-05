// Last updated: 5/6/2026, 5:09:15 pm
class Solution {
public:
    bool isp(vector<int>& piles, int h, int k){
        int n=piles.size();
        for(int i=0;i<n;++i){
            h-=piles[i]/k +1;
            if(piles[i]%k==0) h++;
        }
        return (h>=0?true:false);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=INT_MAX,ans=1;
        while(s<=e){
            int mid=s+((e-s)/2);
            if(isp(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};