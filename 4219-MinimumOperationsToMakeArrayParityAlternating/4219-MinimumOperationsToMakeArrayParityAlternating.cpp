// Last updated: 5/6/2026, 5:06:01 pm
class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n=nums.size();
        int c0=0,c1=0;
        for(int i=0;i<n;++i){
            int p=abs(nums[i])%2;
            if(p==(i%2))c1++;
            else c0++;
        }
        int min_ops=std::min(c0,c1);
        auto get_min_diff=[&](int pat){
            vector<pair<int,int>>v;
            for(int i=0;i<n;++i){
                int p=abs(nums[i])%2;
                int exp=(pat+i)%2;
                if(p==exp)v.push_back({nums[i],i});
                else{
                    v.push_back({nums[i]-1,i});
                    v.push_back({nums[i]+1,i});
                }
            }
            sort(v.begin(),v.end());
            vector<int>f(n,0);
            int uc=0,l=0,ans=INT_MAX;
            for(int r=0;r<v.size();++r){
                if(++f[v[r].second]==1)uc++;
                while(uc==n){
                    ans=min(ans,v[r].first-v[l].first);
                    if(--f[v[l].second]==0)uc--;
                    l++;
                }
            }
            return ans;
        };
        int d=INT_MAX;
        if(c0==min_ops)d=min(d,get_min_diff(0));
        if(c1==min_ops)d=min(d,get_min_diff(1));
        return{min_ops,d};
    }
};