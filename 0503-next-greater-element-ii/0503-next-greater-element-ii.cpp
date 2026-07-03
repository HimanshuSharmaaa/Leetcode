class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() * 2, ori = nums.size();
        vector<int> ans(n / 2, -1);
        stack<int> st;

        for (int i = n - 1; i > -1; i--) {
            while (!st.empty() && st.top() <= nums[i % ori]) {
                st.pop();
            }

            if (i < ori && !st.empty() && st.top() > nums[i % ori]) ans[i % ori] = st.top();
            st.push(nums[i % ori]);
        }

        return ans;
    }
};