class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int max_val = *max_element(nums.begin(), nums.end());
        int maxSum = 1, cumSum = 0;
        unordered_map<int, int> freq;
        map<int,int> diff;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0), r = min(nums[i]+k, max_val);
            diff[l]++, diff[r+1]--;
            diff[nums[i]] += 0;
        }

        for(auto it = diff.begin(); it != diff.end(); it++) {
            it->second += cumSum;
            cumSum = it->second;

            int remainig = it->second - freq[it->first];
            maxSum = max(min(remainig, numOperations) + freq[it->first], maxSum);
        }        

        return maxSum;
    }
};