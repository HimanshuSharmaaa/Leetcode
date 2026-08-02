class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> dec(nums.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            dec[queries[i][0]]--;
            if (queries[i][1] + 1 < nums.size()) dec[queries[i][1] + 1]++;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) dec[i] += dec[i-1];
            nums[i] += dec[i];
            if(nums[i] > 0) return false;
        }

        // for(int i : nums) if(i > 0) return false;
        return true;
    }
};