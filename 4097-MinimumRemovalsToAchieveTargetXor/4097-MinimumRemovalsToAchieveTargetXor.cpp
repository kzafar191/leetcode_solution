// Last updated: 5/6/2026, 5:07:07 pm
class Solution{
public:
    void recur(int lvl,int endLvl,vector<int>&nums,vector<int>&f,int currXor,int kept){
        if(lvl==endLvl){
            f[currXor]=max(f[currXor],kept);
            return;
        }
        recur(lvl+1,endLvl,nums,f,currXor,kept);
        recur(lvl+1,endLvl,nums,f,currXor^nums[lvl],kept+1);
    }
    int minRemovals(vector<int>&nums,int target){
        int n=nums.size();
        int mid=n/2;
        vector<int> leftMap(16384,-1);
        vector<int> rightMap(16384,-1);
        recur(0,mid,nums,leftMap,0,0);
        recur(mid,n,nums,rightMap,0,0);
        int maxKept=-1;
        for(int i=0;i<16384;++i){
            if(leftMap[i]!=-1){
                int needed=i^target;
                if(needed<16384&&rightMap[needed]!=-1){
                    maxKept=max(maxKept,leftMap[i]+rightMap[needed]);
                }
            }
        }
        if(maxKept==-1)return -1;
        return n-maxKept;
    }
};