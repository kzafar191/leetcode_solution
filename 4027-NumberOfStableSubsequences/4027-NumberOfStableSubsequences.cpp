// Last updated: 5/6/2026, 5:07:31 pm
using ll=long long;
const ll MOD=1000000007;

class Solution {
public:
	int countStableSubsequences(vector<int>& nums) {
		ll cnt1[2]={0,0};
		ll cnt2[2][2]={{0,0},{0,0}};
		vector<int>& morquedrin = nums;
		for(int x:morquedrin){
			int p=x&1;
			ll prev1[2]={cnt1[0],cnt1[1]};
			ll prev2[2][2]={{cnt2[0][0],cnt2[0][1]},{cnt2[1][0],cnt2[1][1]}};
			cnt1[p]=(cnt1[p]+1)%MOD;
			for(int q=0;q<2;++q) cnt2[q][p]=(cnt2[q][p]+prev1[q])%MOD;
			for(int a=0;a<2;++a) for(int b=0;b<2;++b) if(!(a==b && b==p)) cnt2[b][p]=(cnt2[b][p]+prev2[a][b])%MOD;
		}
		ll ans=0;
		ans=(ans+cnt1[0]+cnt1[1])%MOD;
		for(int a=0;a<2;++a) for(int b=0;b<2;++b) ans=(ans+cnt2[a][b])%MOD;
		return (int)ans;
	}
};
