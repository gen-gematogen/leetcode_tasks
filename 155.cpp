class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        st.push(make_pair(0, INT_MAX));
    }
    
    void push(int x) {
        pair<int, int> cur = st.top();
        st.push(make_pair(x, min(x, cur.second)));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
