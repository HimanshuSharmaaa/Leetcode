class Solution {
public:
    static bool compare(const int &a, const int &b) {
        return abs(a) < abs(b);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        int i = 0, j = nums.size() - 1;
        long long result = 0;

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