class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int total = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            vector<int> freq(101, 0);
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (freq[nums[j]] == 0) distinct++;

                freq[nums[j]]++;
                total += distinct * distinct;
            }
        }

        return total;
    }
};