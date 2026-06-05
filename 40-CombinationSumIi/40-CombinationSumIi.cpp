// Last updated: 5/6/2026, 5:10:53 pm

class Solution {
public:
    void dfs(vector<vector<int>>& r, vector<int>& c, vector<int>& cur, int t, int s, int idx){
        if(s == t){ r.push_back(cur); return; }
        for(int i = idx; i < (int)c.size(); ++i){
            if(i > idx && c[i] == c[i-1]) continue;
            if(s + c[i] > t) break;
            cur.push_back(c[i]);
            dfs(r, c, cur, t, s + c[i], i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>> r;
        vector<int> cur;
        dfs(r, c, cur, t, 0, 0);
        return r;
    }
};
