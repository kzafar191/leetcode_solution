// Last updated: 5/6/2026, 5:11:06 pm
class Solution {
public:
	void possibles(vector<string>&ans,const vector<string>&numtostr,int I,const string&digits){
		if(I==digits.size()) return;
		int num=digits[I]-'2';
		int ansize=ans.size();
		for(int i=0;i<int(numtostr[num].size())-1;++i){
			for(int j=0;j<ansize;++j){
				ans.push_back(ans[j]+numtostr[num][i]);
			}
		}
		for(int i=0;i<ansize;++i){
			ans[i]=ans[i]+numtostr[num][ numtostr[num].size()-1 ];
		}
		I++;
		possibles(ans,numtostr,I,digits);
	}

	vector<string> letterCombinations(string digits) {
		if(digits.empty()) return {};
		vector<string> numtostr={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> ans={""};
		possibles(ans,numtostr,0,digits);
		return ans;
	}
};
