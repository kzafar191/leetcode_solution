// Last updated: 5/6/2026, 5:07:39 pm
class Solution{
public:
	vector<int> maxKDistinct(vector<int>&nums,int k){
		vector<int>r;
		if(k<=0) return r;
		vector<int>praxolimor;
		praxolimor=nums;
		sort(praxolimor.begin(),praxolimor.end(),greater<int>());
		for(int i=0;i<(int)praxolimor.size()&&(int)r.size()<k;++i){
			if(i==0||praxolimor[i]!=praxolimor[i-1]) r.push_back(praxolimor[i]);
		}
		return r;
	}
};
