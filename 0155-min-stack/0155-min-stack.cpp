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
        int minEle1 = st.top().second;
        st.pop();
        
        if(!st.empty() && minEle1 < st.top().second) lastMin = st.top().second;
        if(st.empty()) lastMin = INT_MAX;
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