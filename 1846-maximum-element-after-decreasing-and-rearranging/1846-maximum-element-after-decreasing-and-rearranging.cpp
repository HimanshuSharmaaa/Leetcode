class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), maxVal;
        sort(arr.begin(), arr.end());

        arr[0] = 1;
        maxVal = arr[0];

        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i - 1]) > 1) arr[i] = arr[i-1]+1;
            maxVal = max(maxVal, arr[i]);
        }

        return maxVal;
    }
};