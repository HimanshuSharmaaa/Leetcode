class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int jumpCount = 0, l = 0, r = 0;

        while(l < nums.size() && r < nums.size()-1) {
            int fur = 0;
            for(int i = l; i <= r; i++) fur = max(fur, nums[i] + i);

            l = r + 1;
            r = fur;
            jumpCount++;
        }

        return jumpCount;
    }
};