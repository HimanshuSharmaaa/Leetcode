class Solution {
public:
    int m, n;
    bool dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= m || col < 0 || col >= n) return false;

        if(grid[row][col] == 1) return true;
        grid[row][col] = 1;

        bool left_dfs = dfs(grid, row, col-1);
        bool right_dfs = dfs(grid, row, col+1);
        bool up_dfs = dfs(grid, row-1, col);
        bool down_dfs = dfs(grid, row+1, col);

        return left_dfs && right_dfs && up_dfs && down_dfs;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    if(dfs(grid, i, j)) count += 1;
                }
            }
        }

        return count;
    }
};