class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, odd = 1, even = 1;

        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] % 2 != 0) minOdd = min(minOdd, nums1[i]);
            if(nums1[i] % 2 != 0) even = 0;
            if(nums1[i] % 2 == 0) odd = 0;
        }
        
        if(even || odd) return true;

        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] % 2 == 0 && (nums1[i] - minOdd) < 1) return false;
        }

        return true;
    }
};