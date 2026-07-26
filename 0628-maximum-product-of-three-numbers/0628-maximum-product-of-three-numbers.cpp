class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int fM = INT_MIN, sM = INT_MIN, tM = INT_MIN;
        int fL = INT_MAX, sL = INT_MAX;

        for (int x : nums) {

            // Three largest numbers
            if (x >= fM) {
                tM = sM;
                sM = fM;
                fM = x;
            }
            else if (x >= sM) {
                tM = sM;
                sM = x;
            }
            else if (x > tM) {
                tM = x;
            }

            // Two smallest numbers
            if (x <= fL) {
                sL = fL;
                fL = x;
            }
            else if (x < sL) {
                sL = x;
            }
        }

        return max(fM * sM * tM, fM * fL * sL);
    }
};