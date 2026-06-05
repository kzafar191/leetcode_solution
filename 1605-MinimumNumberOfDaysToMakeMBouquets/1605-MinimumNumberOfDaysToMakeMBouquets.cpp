// Last updated: 5/6/2026, 5:08:55 pm
class Solution {
public:
bool isp(vector<int>& bloomDay,int m,int k,int day){
    int kk=k,count=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day) kk--;
        else kk=k;
        if(kk==0){count++; kk=k;}
        if(count==m) return true;
    }
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
        int s=0,n=bloomDay.size();
        int e=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>e) e=bloomDay[i];
        }
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(isp(bloomDay,m,k,mid)){
                e=mid-1;
                ans=mid;
            }
            else s=mid+1;
        }
        return ans;
    }
};