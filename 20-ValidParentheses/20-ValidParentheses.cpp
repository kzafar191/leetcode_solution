// Last updated: 5/6/2026, 5:11:02 pm
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if (abs(top - c) > 2) return false;
            }
        }
        return st.empty();
    }
};