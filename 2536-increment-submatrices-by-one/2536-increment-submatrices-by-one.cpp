class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int i = 0; i < q.size(); i++) {
            int r1 = q[i][0], c1 = q[i][1], r2 = q[i][2], c2 = q[i][3];

            for (int i = r1; i <= r2; i++) result[i][c1]++;

            if (c2 + 1 < n) {
                for (int i = r1; i <= r2; i++) result[i][c2+1]--;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                result[i][j] += result[i][j - 1];
            }
        }

        return result;
    }
};