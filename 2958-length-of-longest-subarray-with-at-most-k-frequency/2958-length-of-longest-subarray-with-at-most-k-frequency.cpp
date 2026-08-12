class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int i = 0, j = 0, lon = 0;

        while(j < nums.size()) {
            mpp[nums[j]]++;

            while(mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            lon = max(lon, j - i + 1);
            j++;
        }

        return lon;
    }
};