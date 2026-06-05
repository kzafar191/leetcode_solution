// Last updated: 5/6/2026, 5:09:37 pm
class Solution {
public:
	int splitArray(vector<int>& nums,int k){
		long long low=0,high=0;
		for(int x:nums){
			if(x>low) low=x;
			high+=x;
		}
		while(low<high){
			long long mid=low+(high-low)/2;
			int parts=1;
			long long cur=0;
			for(int x:nums){
				if(cur+x<=mid) cur+=x;
				else{
					++parts;
					cur=x;
				}
			}
			if(parts<=k) high=mid;
			else low=mid+1;
		}
		return (int)low;
	}
};
