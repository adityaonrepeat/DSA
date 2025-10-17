// https://leetcode.com/problems/coloring-a-border/

class Solution {
public:

    int m;
    int n;
    vector<vector<bool>>visited;
    int borderColor = -1;
    int initialColor = -1;
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isBorder(int row, int col, vector<vector<int>>& grid){

        // checking boundry

        if(row == 0 || row == m-1 || col == 0 || col == n-1) return true;

        // chercking other cell

        int currCol = grid[row][col];

        if(
            ( grid[row][col+1] != currCol && visited[row][col+1] == false) ||
            ( grid[row+1][col] != currCol && visited[row+1][col] == false) ||
            ( grid[row][col-1] != currCol && visited[row][col-1] == false) ||
            ( grid[row-1][col] != currCol&& visited[row-1][col] == false) 
        ) return true;

        return false;
    }

    void dfs(int row, int col, vector<vector<int>>& grid){
        
        if(row<0 || row >= m || col < 0 || col >= n || visited[row][col] == true || grid[row][col] != initialColor) return;

        visited[row][col] = true;
        if(isBorder(row, col, grid)) grid[row][col] = borderColor;

        for(auto d: dir){
            int newRow = row + d[0];
            int newCol = col + d[1];

            dfs(newRow, newCol, grid);
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        m = grid.size();
        n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        borderColor = color;
        initialColor = grid[row][col];

        dfs(row, col, grid);

        return grid;
    }
};
