// Last updated: 5/6/2026, 5:08:02 pm
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minp = 1e9+1;
        for(int i=0;i<n;++i) minp = min(minp,items[i][1]);

        vector<long long> freq(1e5+1,0);

        for(int i=0;i<n;++i) freq[items[i][0]]++;

        vector<long long> m(1e5+1,0);
        for(int i=1;i<=1e5;++i){
            if(freq[i]==0) continue;

            long long count = 0;
            for(int j=i;j<=1e5;j+=i){
                count+=freq[j];
            }
            m[i] = count;
        }

        map<int, long long> price;

        for(auto& item: items){
            int f = item[0];
            int p = item[1];

            if(p<2*minp){
                if(m[f]>1){
                    price[p]+= m[f]-1;
                }
            }
        }

        long long two = 0;
        long long left = budget;
        
        for(auto& [p,c]: price){
            if(left<p) break;

            long long t;
            if(c>left/p) t=left/p;
            else t = c;
            two += t;
            left-=t*p;
        }

        return 2*two + left/minp;
    }
};