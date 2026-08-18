class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> mpp(51, 0);
        int ans = -1;

        if (k == 1 || k == nums.size()) {
            for (int i = 0; i < nums.size(); i++) mpp[nums[i]]++;

            if(k == 1) {
                for (int i = 0; i < mpp.size(); i++) if (mpp[i] == 1) ans = max(ans, i);
                return ans;
            } else {
                for (int i = 0; i < mpp.size(); i++) if (mpp[i] > 0) ans = max(ans, i);
                return ans;    
            }
        }

        for (int i = 0; i <= nums.size() - k; i++) {
            for (int j = i; j < i+k; j++) mpp[nums[j]]++;
        }

        for (int i = 0; i < mpp.size(); i++) {
            if (mpp[i] == 1) ans = max(ans, i);
        }

        return ans;
    }
};