class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zeroCount = count(nums.begin(), nums.end(), 0);
        if(zeroCount == nums.size()) return 0;
        
        int x = 0;

        for(int num : nums) x = x ^ num;

        if(x != 0) return nums.size();
        else return nums.size()-1;
    }
};