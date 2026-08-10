class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int i = 0; i < q.size(); i++) {
            int r1 = q[i][0], c1 = q[i][1], r2 = q[i][2], c2 = q[i][3];

            result[r1][c1]++;
            if (c2 + 1 < n) result[r1][c2+1]--;
            if (r2 + 1 < n) result[r2+1][c1]--;
            if (c2 + 1 < n && r2 + 1 < n) result[r2+1][c2+1]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                result[i][j] += result[i][j - 1];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                result[j][i] += result[j-1][i];
            }
        }

        return result;
    }
};