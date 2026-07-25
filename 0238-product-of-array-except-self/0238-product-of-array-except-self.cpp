class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), pre = 1;
        vector<int> suffix(n, 1);

        for(int i = n-2; i >= 0; i--) suffix[i] = nums[i+1] * suffix[i+1];

        for(int i = 0; i < n; i++){
            suffix[i] = pre * suffix[i];
            pre = pre * nums[i];
        }

        return suffix;
    }
};