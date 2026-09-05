class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int right = INT_MAX, left = 0;
        vector<int> rightSum(nums.size());

        for(int i = nums.size()-1; i > -1; i--) {
            if(nums[i] < right) right = nums[i];
            rightSum[i] = right;
        }

        for(int i = 0; i < nums.size(); i++) {
            left = max(left, nums[i]);
            if(left - min(rightSum[i], nums[i]) <= k) return i;
        }

        return -1;
    }
};