class Solution {
public:
    int m, n;
    vector<vector<int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    long long dfs(vector<vector<int>>& grid, int row, int col) {
        long long sum = grid[row][col];
        grid[row][col] = 0;

        for (vector<int>& dir : direction) {
            int i = row + dir[0], j = col + dir[1];
            if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] > 0) {
                sum += dfs(grid, i, j);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    if (dfs(grid, i, j) % k == 0) count++;
                }
            }
        }

        return count;
    }
};