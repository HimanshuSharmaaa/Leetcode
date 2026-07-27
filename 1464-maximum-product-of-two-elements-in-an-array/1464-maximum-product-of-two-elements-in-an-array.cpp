class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fM = INT_MIN, sM = INT_MIN;

        for(int i : nums) {
            if(fM <=  i) {
                sM = fM;
                fM = i;
            } else if(i < fM && i > sM) sM = i;
        }

        return (fM-1)*(sM-1);
    }
};