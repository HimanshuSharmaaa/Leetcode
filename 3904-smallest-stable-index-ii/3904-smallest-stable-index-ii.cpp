class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), right = INT_MAX, left = 0, stable = -1;
        vector<int> rightSum(n, INT_MAX);

        for(int i = n-1; i > -1; i--) {
            right = min(right, nums[i]);
            rightSum[i] = min(rightSum[i], right);
        }

        for(int i = 0; i < n; i++) {
            left = max(left, nums[i]);
            if(left- min(rightSum[i], nums[i]) <= k) {
                stable = i;
                break;
            }
        }

        return stable;
    }
};