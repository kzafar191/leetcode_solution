// Last updated: 5/6/2026, 5:08:18 pm
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        
        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        vector<int> st;
        for (int id : ids) {
            if (directions[id] == 'R') {
                st.push_back(id);
            } else {
                while (!st.empty() && directions[st.back()] == 'R' && healths[id] > 0) {
                    if (healths[st.back()] < healths[id]) {
                        healths[st.back()] = 0;
                        st.pop_back();
                        healths[id] -= 1;
                    } else if (healths[st.back()] > healths[id]) {
                        healths[st.back()] -= 1;
                        healths[id] = 0;
                    } else {
                        healths[st.back()] = 0;
                        st.pop_back();
                        healths[id] = 0;
                    }
                }
                if (healths[id] > 0) {
                    st.push_back(id);
                }
            }
        }
        
        sort(st.begin(), st.end());
        
        vector<int> ans;
        for (int id : st) {
            ans.push_back(healths[id]);
        }
        
        return ans;
    }
};