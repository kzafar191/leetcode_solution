// Last updated: 5/6/2026, 5:08:30 pm
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& p) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> in, out;
        
        for (const auto& pair : p) {
            g[pair[0]].push_back(pair[1]);
            out[pair[0]]++;
            in[pair[1]]++;
        }
        
        int start = p[0][0]; 
        for (const auto& [x, o] : out) {
            if (o - in[x] == 1) {
                start = x;
                break;
            }
        }
        
        vector<int> path;
        stack<int> s;
        s.push(start);
        
        while (!s.empty()) {
            int c = s.top();
            
            if (!g[c].empty()) {
                int n = g[c].back();
                g[c].pop_back();  
                s.push(n);         
            } 
            else {
                path.push_back(c);  
                s.pop();              
            }
        }
        
        vector<vector<int>> res;
        for (int i = path.size() - 1; i > 0; --i) {
            res.push_back({path[i], path[i - 1]});
        }
        
        return res;
    }
};