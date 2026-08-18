class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int ans = -1;

        if (k == 1 || k == nums.size()) {
            for (int i = 0; i < nums.size(); i++) mpp[nums[i]]++;

            if(k == 1) {
                for (auto& [key, val] : mpp) if (val == 1) ans = max(ans, key);
                return ans;
            } else {
                for (auto& [key, val] : mpp) ans = max(ans, key);
                return ans;    
            }
        }

        for (int i = 0; i <= nums.size() - k; i++) {
            for (int j = i; j < i+k; j++) mpp[nums[j]]++;
        }

        for (auto& [key, val] : mpp) {
            if (val == 1) ans = max(ans, key);
        }

        return ans;
    }
};