class Solution {
public:
    void BFS(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col, int& area){
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = true;

        int totalRows = grid.size();
        int totalCols = grid[0].size();
        int localArea = 1;

        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            int currRow = node.first;
            int currCol = node.second;
            // cout << "Inside while" << currRow << " " << currCol << endl;

            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                    if(abs(deltaCol) == abs(deltaRow)) continue;
                    int newRow = currRow + deltaRow;
                    int newCol = currCol + deltaCol;
                    // cout << "Inside while -> for " << newRow << " " << newCol << endl;

                    if(newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols 
                        && vis[newRow][newCol] == false && grid[newRow][newCol] == 1){
                            localArea++;

                            vis[newRow][newCol] = true;
                            q.push({newRow, newCol});
                        }
                }
            }
        }
        area = max(area, localArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(vis[i][j] == false && grid[i][j] == 1){
                    // cout << i << " " << j << endl;
                    BFS(grid, vis, i, j, area);
                }
            }
        }

        return area;
    }
};
