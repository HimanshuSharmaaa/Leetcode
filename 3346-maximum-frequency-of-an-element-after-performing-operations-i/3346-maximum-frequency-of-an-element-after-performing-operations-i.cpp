class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int max_val = *max_element(nums.begin(), nums.end()) + k;
        vector<int> diff(max_val+2, 0);
        unordered_map<int, int> freq;
        int maxSum = 1;

        for(int i = 0; i < nums.size(); i++) {
            int l = max(nums[i]-k, 0), r = min(nums[i]+k, max_val);
            diff[l]++, diff[r+1]--;
            freq[nums[i]]++;
        }

        for(int i = 0; i <= max_val; i++) {
            diff[i] += (i > 0 ? diff[i-1] : 0);

            int remainig = diff[i] - freq[i];
            maxSum = max(min(remainig, numOperations) + freq[i], maxSum);
        }        

        return maxSum;
    }
};