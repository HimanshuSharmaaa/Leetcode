class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mpp;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int rank = 1;

        for(int i = 0; i < sorted.size(); i++){
            if(i > 0 && sorted[i] != sorted[i-1]) rank++;
            mpp[sorted[i]] = rank;
        }

        for(int i = 0; i < arr.size(); i++) arr[i] = mpp[arr[i]];
        return arr;
    }
};