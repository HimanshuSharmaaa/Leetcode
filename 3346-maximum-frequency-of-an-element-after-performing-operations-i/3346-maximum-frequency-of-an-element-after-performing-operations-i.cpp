class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int max_val = *max_element(nums.begin(), nums.end()) + k;
        unordered_map<int, int> freq;
        int ans = 1, cumSum = 0;
        map<int, int> diff;

        for (int val : nums) {
            freq[val]++;

            int l = max(0, val - k), r = min(val + k, max_val);
            diff[l]++;
            diff[r + 1]--;
            diff[val] += 0;
        }

        for(auto it = diff.begin(); it != diff.end(); it++) {
            it->second += cumSum;
            cumSum = it->second;

            int needed = it->second - freq[it->first];
            ans = max(ans, min(needed, numOperations) + freq[it->first]);
        }

        return ans;
    }
};