class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), cols = grid[0].size(), t = 0;
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({0, {i, j}});
            }
        }

        while (!q.empty()) {
            auto ele = q.front();

            int time = ele.first;
            int i = ele.second.first;
            int j = ele.second.second;
            t = max(t, time);
            q.pop();

            // Top
            if (i > 0 && grid[i - 1][j] == 1) {
                q.push({time + 1, {i - 1, j}});
                grid[i - 1][j] = 2;
            }

            // Bottom
            if (i < row - 1 && grid[i + 1][j] == 1) {
                q.push({time + 1, {i + 1, j}});
                grid[i + 1][j] = 2;
            }

            // Right
            if (j < cols - 1 && grid[i][j + 1] == 1) {
                q.push({time + 1, {i, j + 1}});
                grid[i][j + 1] = 2;
            }

            // Left
            if (j > 0 && grid[i][j - 1] == 1) {
                q.push({time + 1, {i, j - 1}});
                grid[i][j - 1] = 2;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return t;
    }
};