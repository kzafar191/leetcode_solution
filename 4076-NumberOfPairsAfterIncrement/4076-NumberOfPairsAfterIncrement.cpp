// Last updated: 5/6/2026, 5:07:15 pm
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> ans;

        double rt = 1.0*sqrt(nums2.size());
        int blz = ceil(rt);

        vector<vector<long long>> block;

        int n = nums2.size();
        int idx=0;
        while(idx<n){
            block.push_back({});
            for(int j=0;idx<n&& j<blz;++j){
                block[block.size()-1].push_back(nums2[idx]);
                idx++;
            }
        }
        int nB = block.size();
        vector<long long> add(nB,0);
        vector<unordered_map<long long,int>> freq(nB);

        for(int i=0;i<nB;++i){
            for(int j=0;j<block[i].size();++j){
                freq[i][block[i][j]]++;
            }
        }

        for(int q=0;q<queries.size();++q){
            if (queries[q][0] == 1) {
                int x = queries[q][1];
                int y = queries[q][2];
                int val = queries[q][3];
                int bl = x / blz;
                int prior = x % blz;
                int to = y / blz;
            
                if (bl == to) {
                    int end_idx = y % blz;
                    for (int i = prior; i <= end_idx; ++i) {
                        freq[bl][block[bl][i]]--;
                        block[bl][i] += val;
                        freq[bl][block[bl][i]]++;
                    }
                } 
                else {
                    for (int i = prior; i < block[bl].size(); ++i) {
                        freq[bl][block[bl][i]]--;
                        block[bl][i] += val;
                        freq[bl][block[bl][i]]++;
                    }
            
                    for (int i = bl + 1; i < to; ++i) {
                        add[i] += val;
                    }
            
                    int end_idx = y % blz;
                    for (int i = 0; i <= end_idx; ++i) {
                        freq[to][block[to][i]]--;
                        block[to][i] += val;
                        freq[to][block[to][i]]++;
                    }
                }
            }
            else{
                ans.push_back(0);
                int tot = queries[q][1];
                for(int i=0;i<nums1.size();++i){
                    for(int j=0;j<nB;++j){
                        int tofind = tot-nums1[i]-add[j];
                        int temp=0;
                        if(freq[j].count(tofind)) temp = freq[j][tofind];
                        ans[ans.size()-1]+=temp;
                    }
                }
            }
        }
        return ans;
    }
};