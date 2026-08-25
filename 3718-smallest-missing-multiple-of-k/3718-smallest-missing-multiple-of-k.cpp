class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        int x = k;

        for(int i : nums) st.insert(i);

        while(st.count(x)) {
            x += k;
        }

        return x;
    }
};