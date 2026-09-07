class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), sum = 0, nse, ele, pse;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && h[st.top()] > h[i]) {
                nse = i;

                while (!st.empty() && h[st.top()] > h[i]) {
                    ele = h[st.top()];
                    st.pop();
                    pse = (!st.empty() ? st.top() : -1);
                    sum = max(sum, (nse - pse - 1) * ele);
                }
            }
            st.push(i);
        }

        while (!st.empty()) {
            ele = h[st.top()];
            st.pop();
            pse = (!st.empty() ? st.top() : -1);
            sum = max(sum, (n - pse - 1) * ele);
        }

        return sum;
    }
};