class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mpp;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int rank = 1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i > 0 && sorted[i] != sorted[i - 1]) rank++;
            mpp[sorted[i]] = rank;
        }

        for (int i = 0; i < arr.size(); i++) arr[i] = mpp[arr[i]];
        return arr;
    }
};

// unordered_map<int, int> map;
//         vector<int> st = arr;
//         sort(st.begin(), st.end());
//         int i = 1;
//         for (int s : st) {
//             if(map.find(s)==map.end()){

//             map[s] = i;
//             i++;
//             }
//         }
//         for (int i = 0; i < arr.size(); i++) {
//             arr[i] = map[arr[i]];
//         }
//         return arr;