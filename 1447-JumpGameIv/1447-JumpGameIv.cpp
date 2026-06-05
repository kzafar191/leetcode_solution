// Last updated: 5/6/2026, 5:09:00 pm
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; 

        unordered_map<int, vector<int>> ump;
        vector<int> dp(n, 1e7); 
        
        for(int i = 0; i < n; ++i){
            ump[arr[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);
        dp[0] = 0;

        while(!que.empty()){
            int curr = que.front();
            que.pop();

            if (curr == n - 1) {
                return dp[curr];
            }
            for (int next_idx : ump[arr[curr]]) {
                if (dp[curr] + 1 < dp[next_idx]) {
                    dp[next_idx] = dp[curr] + 1;
                    que.push(next_idx);
                }
            }
            ump[arr[curr]].clear(); 

            if (curr + 1 < n && dp[curr] + 1 < dp[curr + 1]) {
                dp[curr + 1] = dp[curr] + 1;
                que.push(curr + 1);
            }

            if (curr - 1 >= 0 && dp[curr] + 1 < dp[curr - 1]) {
                dp[curr - 1] = dp[curr] + 1;
                que.push(curr - 1);
            }
        }
        
        return 0;
    }
};