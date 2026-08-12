class Solution {
   public:
    void BFS(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            int currRow = node.first;
            int currCol = node.second;

            for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
                for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
                     if(abs(deltaRow) == abs(deltaCol)) continue;
                    int newRow = currRow + deltaRow;
                    int newCol = currCol + deltaCol;

                    if(newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols
                        && vis[newRow][newCol] == false && grid[newRow][newCol] == '1')
                    {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (vis[i][j] == false && grid[i][j] == '1') {
                    cout << i << " " << j << endl;
                    BFS(grid, vis, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
