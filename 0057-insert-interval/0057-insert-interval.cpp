class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        int i = 0, j = 0, n = in.size();
        vector<vector<int>> result;

        while(i < n && in[i][1] < newIn[0]) {
            result.push_back({in[i][0], in[i][1]});
            i++;
        }

        while(i < n && in[i][0] <= newIn[1]) {
            newIn[0] = min(in[i][0], newIn[0]);
            newIn[1] = max(in[i][1], newIn[1]);
            i++;
        }

        result.push_back({newIn[0],newIn[1]});

        while(i < n) {
            result.push_back({in[i][0], in[i][1]});
            i++;
        }

        return result;
    }
};