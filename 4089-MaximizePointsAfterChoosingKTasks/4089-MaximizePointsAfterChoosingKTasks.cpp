// Last updated: 5/6/2026, 5:07:08 pm
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long sum = 0;
        int t1=0;
        vector<long long> diff;
        for(int i=0;i<n;++i){
            if(technique1[i]>=technique2[i]){
                sum+=technique1[i];
                t1++;
            }
            else {
                sum+=technique2[i];
                diff.push_back(technique2[i]-technique1[i]);
            }
        }
        sort(diff.begin(),diff.end());
        int req= k-t1;
        int curr=0;
        while(req>0){
            sum-=diff[curr];
            curr++; req--;
        }
        return sum;
    }
};