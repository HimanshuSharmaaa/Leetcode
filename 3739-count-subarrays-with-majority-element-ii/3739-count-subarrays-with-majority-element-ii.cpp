class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0, presum = 0;
        int n = nums.size(), cnt = n;

        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }
            ans += presum;
        }
        return ans;
    }
};