class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long i = 0, j = nums.size() - 1;
        long long result = 0;

        for (int p = 0; p < nums.size(); p++) nums[p] = abs(nums[p]);
        sort(nums.begin(), nums.end());

        while (i <= j) {
            if (i == j) {
                result += nums[j] * nums[j];
                break;
            }

            result += (nums[j] * nums[j]) - (nums[i] * nums[i]);
            i++, j--;
        }

        return result;
    }
};