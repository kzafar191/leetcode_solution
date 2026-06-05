// Last updated: 5/6/2026, 5:07:55 pm
class Solution{
public:
    int countTrapezoids(vector<vector<int>>&points){
        unordered_map<int,int>Y;
        int n=points.size();
        for(int i=0;i<n;++i){
            Y[points[i][1]]++;
        }
        long long ans=0,mod=1e9+7;
        long long runningSum=0;
        for(auto it:Y){
            long long x=it.second;
            if(x<2)continue;
            long long add=(x*(x-1)/2)%mod;
            ans=(ans+runningSum*add)%mod;
            runningSum=(runningSum+add)%mod;
        }
        return ans;
    }
};