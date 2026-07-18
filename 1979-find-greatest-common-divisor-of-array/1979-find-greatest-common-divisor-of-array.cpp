class Solution {
public:
    int calGCD(int a, int b){
        while(a != 0 && b != 0){
            if(a > b) a = a % b;
            else b = b % a;
        }

        return max(a,b);
    }

    int findGCD(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());

        return calGCD(minEle, maxEle);
    }
};