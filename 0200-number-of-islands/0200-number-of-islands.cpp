class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    bool valid(int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int row, int col,
             vector<vector<bool>>& vis) {

        vis[row][col] = true;

        int n = grid.size();
        int m = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int newRow = row + dr[k];
            int newCol = col + dc[k];

            if (valid(newRow, newCol, n, m) &&
                grid[newRow][newCol] == '1' &&
                !vis[newRow][newCol]) {

                dfs(grid, newRow, newCol, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(grid, i, j, vis);
                }
            }
        }

        return ans;
    }
};