// https://leetcode.com/problems/cherry-pickup
class Solution {
public:
    int dp[51][51][51][51];
    int fn(vector<vector<int>>& grid, int i, int j, int k, int l) {
        int n = grid.size(), m = grid[0].size();

        // Out-of-bounds or blocked cell
        if (i >= n || j >= m || k >= n || l >= m)
            return -1e9;
        if (grid[i][j] == -1 || grid[k][l] == -1)
            return -1e9;

        // Both reached the end
        if (i == n - 1 && j == m - 1 && k == n - 1 && l == m - 1)
            return grid[i][j];

        if(dp[i][j][k][l]!= -1) return dp[i][j][k][l];

        if (i != k || j != l)
            return dp[i][j][k][l] = grid[i][j] + grid[k][l] +
                   max(max(fn(grid, i + 1, j, k + 1, l),
                           fn(grid, i + 1, j, k, l + 1)),
                       max(fn(grid, i, j + 1, k + 1, l),
                           fn(grid, i, j + 1, k, l + 1)));
        else
            return dp[i][j][k][l]  = grid[i][j] + max(max(fn(grid, i + 1, j, k + 1, l),
                                        fn(grid, i + 1, j, k, l + 1)),
                                    max(fn(grid, i, j + 1, k + 1, l),
                                        fn(grid, i, j + 1, k, l + 1)));
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = fn(grid, 0, 0, 0, 0);
        return max(0, ans); // return 0 if no valid path
    }
};
