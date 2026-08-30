class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), minIdx = 0, maxIdx = 0, front = 0, back = 0, mix = 0;
        if(n == 1 || n == 2) return n;

        for(int i = 0; i < n; i++) {
            if(nums[maxIdx] < nums[i]) maxIdx = i;
            if(nums[minIdx] > nums[i]) minIdx = i;
        }

        if(minIdx < maxIdx) {
            front += minIdx+1;
            front += (maxIdx+1) - front;
        } else {
            front += maxIdx+1;
            front += minIdx + 1 - front;
        }

        if(minIdx > maxIdx) {
            back += n - minIdx;
            back += n - maxIdx - back;
        } else {
            back += n - maxIdx;
            back += n - minIdx - back;
        }

        if(minIdx < maxIdx) mix += minIdx + 1 + n - maxIdx; 
        else mix += maxIdx + 1 + n - minIdx; 

        return min(front, min(back, mix));
    }
};