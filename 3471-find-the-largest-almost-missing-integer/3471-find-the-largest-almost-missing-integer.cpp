class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1, n = nums.size();
        vector<int> mpp(51, 0);

        for (int i = 0; i < n; i++) mpp[nums[i]]++;

        if (k == 1 || k == n) {
            if(k == 1) {
                for (int i = 0; i < 51; i++) if (mpp[i] == 1) ans = max(ans, i);
                return ans;
            } else {
                for (int i = 0; i < 51; i++) if (mpp[i] > 0) ans = max(ans, i);
                return ans;    
            }
        }

        if (mpp[nums[0]] == 1) ans = max(ans, nums[0]);
        if (mpp[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);  
        return ans;
    }
};