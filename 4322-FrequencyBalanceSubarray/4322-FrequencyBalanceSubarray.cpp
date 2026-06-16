// Last updated: 16/6/2026, 1:58:04 pm
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;

        for(int i=0;i<n;++i){
            unordered_map<int,int> freq, cnt;
            int mxf = 0;

            for(int j=i;j<n;++j){
                int val = nums[j];

                if(freq.count(val)>0) cnt[freq[val]]--;

                freq[val]++;
                cnt[freq[val]]++;

                mxf = max(mxf, freq[val]);

                int unq = freq.size();

                bool valid = false;

                if(unq==1) valid = true;
                else if(mxf%2==0 && cnt[mxf/2]>0 && (cnt[mxf]+cnt[mxf/2]==unq)) valid = true;
                if(valid) mx = max(mx,j-i+1);
            }
        }
        return mx;
    }
};