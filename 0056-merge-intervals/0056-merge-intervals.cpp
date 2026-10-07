class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> result;
        sort(in.begin(), in.end());
        result.push_back(in[0]);

        for(int i = 1; i < in.size(); i++) {
            if(result.back()[1] < in[i][0]) result.push_back(in[i]);
            else {
                vector<int> &last = result.back();
                last[0] = min(last[0], in[i][0]);
                last[1] = max(last[1], in[i][1]);
            }
        }

        return result;
    }
};