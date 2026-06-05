// Last updated: 5/6/2026, 5:10:04 pm
class MinStack {
private:
    stack<int> st;
    stack<int> minst;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minst.empty() || val <= minst.top()) {
            minst.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minst.top()) {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};