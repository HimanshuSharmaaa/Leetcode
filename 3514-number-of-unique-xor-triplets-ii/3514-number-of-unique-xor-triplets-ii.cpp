class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int largest = accumulate(nums.begin(), nums.end(), 0);
        int T = 1, count = 0;

        while (T <= largest) T *= 2;

        vector<bool> st1(T, false), st2(T, false);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                st1[nums[i] ^ nums[j]] = true;
            }
        }

        for (int i = 0; i < st1.size(); i++) {
            if (st1[i]) {
                for (int j = 0; j < nums.size(); j++) {
                    st2[i ^ nums[j]] = true;
                }
            }
        }

        for(int i = 0; i < st2.size(); i++) if(st2[i]) count++;
        return count;
    }
};