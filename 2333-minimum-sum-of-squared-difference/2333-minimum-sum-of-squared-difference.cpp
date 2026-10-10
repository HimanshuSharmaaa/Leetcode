
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> vec(100001, 0);
        long long total = 0;
        int k = k1 + k2;

        for (int i = 0; i < nums1.size(); i++) vec[abs(nums1[i] - nums2[i])]++;

        for (int i = 100000; i >= 1 && k > 0; i--) {
            if (vec[i] > 0) {
                int count = min(vec[i], k);
                vec[i] -= count;
                vec[i - 1] += count;
                k -= count;
            }
        }

        for (int i = 0; i < 100001; i++) total += 1LL * vec[i] * i * i;
        return total;
    }
};
