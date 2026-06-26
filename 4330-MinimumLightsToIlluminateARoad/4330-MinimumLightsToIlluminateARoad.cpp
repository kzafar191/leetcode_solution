// Last updated: 26/6/2026, 2:49:48 pm
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> track(n,0);

        for(int i=0;i<n;++i){
            int v = lights[i];
            if(v==0) continue;

            track[max(0,i-v)]++;
            if(i+v+1<=n-1) track[i+v+1]--;
        }

        int ans = 0;
        for(int i=1;i<n;++i){
            track[i] = track[i-1]+track[i];
        }

        int dir=0;
        for(int i=0;i<n;++i){
            if(track[i]==0) dir++;
            else{
                ans += ceil(dir/3.0);
                dir=0;
            }
        }
        ans+= ceil(dir/3.0);
        return ans;
    }
};