// Last updated: 5/6/2026, 5:09:04 pm
class Solution {
public:
	int smallestDivisor(vector<int>& nums,int threshold){
		int low=1,high=0;
		for(int x:nums) if(x>high) high=x;
		while(low<high){
			int mid=low+(high-low)/2;
			long long sum=0;
			for(int x:nums){
				sum += (x+mid-1)/mid;
				if(sum>threshold) break;
			}
			if(sum>threshold) low=mid+1;
			else high=mid;
		}
		return low;
	}
};