// Last updated: 5/6/2026, 5:09:16 pm
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, d = 0, m = 0;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        set<pair<int,int>> s;
        
        for (auto& o : obstacles) s.insert({o[0], o[1]});
        
        for (int c : commands) {
            if (c == -2) d = (d + 3) % 4;
            else if (c == -1) d = (d + 1) % 4;
            else {
                while (c--) {
                    if (s.count({x + dx[d], y + dy[d]})) break;
                    x += dx[d];
                    y += dy[d];
                    m = max(m, x * x + y * y);
                }
            }
        }
        return m;
    }
};