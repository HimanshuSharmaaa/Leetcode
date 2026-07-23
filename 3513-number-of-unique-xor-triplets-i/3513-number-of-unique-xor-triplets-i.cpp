class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int i = 1, n = nums.size();

        while(i <= n) i *= 2;;
        return i;
    }
};