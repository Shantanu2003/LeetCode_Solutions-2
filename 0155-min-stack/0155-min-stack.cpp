class MinStack {
public:
    stack<int> st;
    stack<int>st1;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(st1.empty() || val <= st1.top())
        st1.push(val);
    }
    
    void pop() {
        if(st.top() == st1.top()){
            st1.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {      
        return st1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */