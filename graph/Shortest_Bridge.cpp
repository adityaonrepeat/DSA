class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Find first island and mark it using DFS
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == 1) { // First island found
                    dfs(i, j, grid);
                    return bfs(grid);  // Step 2 & 3: BFS to find shortest bridge
                }
            }
        }
        return -1; // Should never happen as per problem constraints
    }

    // DFS to mark the first island
    void dfs(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        grid[row][col] = -1; // Mark as visited

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // Up, Down, Left, Right

        for(auto x : directions) {
            int new_row = row + x.first;
            int new_col = col + x.second;

            if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n 
               && grid[new_row][new_col] == 1) {
                dfs(new_row, new_col, grid);
            }
        }
    }

    // BFS to find the shortest bridge to second island
    int bfs(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        // Push all cells of first island into BFS queue
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(grid[i][j] == -1) {
                    q.push({i,j});
                }
            }
        }

        int ans = 0; // Number of flips
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()) {
            int size = q.size();
            for(int i=0 ; i<size ; i++) {
                auto [row, col] = q.front(); q.pop();

                for(auto x : directions) {
                    int new_row = row + x.first;
                    int new_col = col + x.second;

                    if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n 
                       && grid[new_row][new_col] != -1) {

                        if(grid[new_row][new_col] == 1) {
                            return ans; // Reached second island
                        }

                        grid[new_row][new_col] = -1; // Mark visited
                        q.push({new_row,new_col});
                    }
                }
            }
            ans++; // Increment flips after each BFS level
        }

        return ans;
    }
};
