class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st;
        int sum = nums[0], j;
        st.insert(sum);

        for(j = 1; j < nums.size(); j++) {
            st.insert(nums[j]);
            if(nums[j-1]+1 == nums[j]) sum += nums[j];
            else break;
        }

        while(j < nums.size()) st.insert(nums[j++]);

        while(st.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};