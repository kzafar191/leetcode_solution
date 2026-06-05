// Last updated: 5/6/2026, 5:07:51 pm
class Solution {
public:
    
    int findp(vector<int>&p,int x){return p[x]==x?x:p[x]=findp (p,p[x]);}
	void unite(vector<int>&p,int a,int b){a=findp(p,a); b=findp (p,b); if(a!=b) p[b]=a;}
    
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
		bool sorted=true;
		for(int i=0;i<n;++i) if(nums[i]!=i){sorted=false;break;}
		if(sorted) return 0;
		int maxv = n-1, B=0;
		while((1<<B)<=maxv) ++B;
		vector<int> pos(n);
		for(int i=0;i<n;++i) pos[nums[i]]=i;
		int mask=0;
		for(int b=B-1;b>=0;--b){
			int cand=mask|(1<<b);
			if(testCand(nums,pos,B,cand)) mask=cand;
		}
		return mask;
    }

	bool testCand(vector<int>&nums,vector<int>&pos,int B,int cand){
		int n=nums.size();
		vector<int> good; good.reserve(n);
		for(int v=0;v<n;++v){
			if((v&cand)!=cand){
				if(pos[v]!=v) return false;
			}else good.push_back(v);
		}
		if(good.empty()) return true;
		vector<int> rem;
		for(int bit=0;bit<B;++bit) if(((cand>>bit)&1)==0) rem.push_back(bit);
		int Bp=rem.size();
		int M=1<<Bp;
		vector<vector<int>> bucket(M);
		for(int v:good){
			int s=0;
			for(int i=0;i<Bp;++i) if((v>>rem[i])&1) s|=(1<<i);
			bucket[s].push_back(v);
		}
		vector<int> p(n);
		for(int i=0;i<n;++i) p[i]=i;
		vector<char> vis(M,0);
		vector<int> q;
        q.reserve(256);
		vector<int> comp; comp.reserve(256);
		for(int s=0;s<M;++s){
			if(vis[s]||bucket[s].empty()) continue;
			q.clear();
            comp.clear();
			q.push_back(s);
            vis[s]=1;
			for(size_t qi=0;qi<q.size();++qi){
				int cur=q[qi];
				comp.push_back(cur);
				int cm=((M-1)^cur);
				for(int sub=cm;;sub=(sub-1)&cm){
					if(!vis[sub]&&!bucket[sub].empty()){
						vis[sub]=1;
						q.push_back(sub);
					}
					if(sub==0) break;
				}
			}
			int base=-1;
			for(int m:comp){
				for(int v:bucket[m]){
					if(base==-1) base=pos[v];
					else unite(p,base,pos[v]);
				}
			}
		}
		for(int i=0;i<n;++i) if(findp(p,i)!=findp(p,nums[i])) return false;
		return true;
	}
};