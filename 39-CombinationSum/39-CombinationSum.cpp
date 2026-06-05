// Last updated: 5/6/2026, 5:10:55 pm
class Solution {
public:

    vector<int> tempList;
    vector<vector<int>> ansList;
    vector<int> cnd;
    void process(int pointer, int currSum){
        if(currSum > 0 && pointer <0) return;
        if(currSum ==0 ){
            ansList.push_back(tempList);
            return;
        }
        process(pointer-1, currSum);
        int addedCnt = 0;
        while(currSum - cnd[pointer] >=0){
            tempList.push_back(cnd[pointer]);
            addedCnt += 1;
            currSum = currSum - cnd[pointer];
            process(pointer-1, currSum );

        }
        for(int i=0; i< addedCnt; i++){
            tempList.pop_back();
            currSum = currSum + cnd[pointer];
        }

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        cnd = candidates;
        process(cnd.size()-1,target);
        return ansList;
    }
};