// Last updated: 5/6/2026, 5:06:52 pm
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(cost1+cost2>costBoth){
            ans+= 1LL*min(need1,need2)*costBoth;
            int tominus = min(need1,need2);
            need1-= tominus;
            need2-= tominus;
        }
        else{
            ans+=1LL*need1*cost1 + 1LL*need2*cost2;
            need1=0;
            need2=0;
        }
        if(need1!=0) ans+=1LL*need1*min(costBoth,cost1);
        else if(need2 !=0) ans+=1LL*need2*min(costBoth,cost2);
        return ans;
    }
};