// Last updated: 5/6/2026, 5:05:28 pm
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> primes(2e5,true);
        primes[1]= false;
        primes[0]= false;
        for(int i=2;i*i<2e5;++i){
            if(primes[i]==false) continue;
            for(long long j=1LL*i*i;j<2e5;j+=i){
                if(primes[j]==false) continue;
                primes[j]= false;
            }
        }
        vector<int> nextprime(2e5);
        int next = 1e6;
        for(int i=2e5 -1;i>=1;--i){
            if(primes[i]) next =i;
            nextprime[i]=next;
        }
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(i&1){
                //if(nums[i]==1) ans+=3;
                if(nums[i]==2) ans+=2;
                else if(primes[nums[i]]) ans++;
            }
            else{
                ans+=nextprime[nums[i]]-nums[i];
            }
        }
        return ans;
    }
};