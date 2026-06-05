// Last updated: 5/6/2026, 5:11:09 pm
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs){
		if(strs.empty()) return "";
		int n=strs.size();
		int minlen=INT_MAX;
		for(int i=0;i<n;++i) if((int)strs[i].size()<minlen) minlen=strs[i].size();
		if(minlen==0) return "";

		for(int idx=0;idx<minlen;++idx){
			char c=strs[0][idx];
			for(int j=1;j<n;++j){
				if(strs[j][idx]!=c) return strs[0].substr(0,idx);
			}
		}
		return strs[0].substr(0,minlen);
	}
};
