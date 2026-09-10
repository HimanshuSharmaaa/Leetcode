class MinStack {
public:
    stack<pair<int,int>> st;
    int lastMin = INT_MAX;
    MinStack() {}
    
    void push(int value) {
        if(lastMin > value) lastMin = value;
        st.push({value, lastMin});
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        
        if(st.empty()) lastMin = INT_MAX;
        else lastMin = st.top().second;
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return st.top().second;
    }
};