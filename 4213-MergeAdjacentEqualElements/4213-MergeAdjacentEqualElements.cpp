// Last updated: 5/6/2026, 5:06:07 pm
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        // for(int i=0;i<n;++i){
        //     if(nums[i]==nums[i+1]){
        //         int l=i-1;
        //         int r = i+1;
        //         int temp = nums[i]*2;
        //         while(l>=start || r<n){
        //             bool found = false;
        //             if(l>=start && temp==nums[l]){
        //                 l--; found = true;
        //             }
        //             else if(r<n && temp==nums[r]){
        //                 r++; found = false;
        //             }
                    
        //         }
        //     }
        // }

        stack <long long> st;
        st.push(nums[0]);
        for(int i=1;i<n;++i){
            long long n1= st.top();
            long long n2 = nums[i];
            while(!st.empty()){
                n1 = st.top();
                if(n1==n2){
                    st.pop();
                    n2=n1*2;
                }
                else break;
            }
            st.push(n2);
        }
        vector<long long> rev;
        while(!st.empty()){
            rev.push_back(st.top()); st.pop();
        }
        for(int i=0;i<rev.size()/2;++i) swap(rev[i],rev[rev.size()-1-i]);
        return rev;
    }
};