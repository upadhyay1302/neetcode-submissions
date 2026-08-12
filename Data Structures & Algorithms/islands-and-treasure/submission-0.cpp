class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        
        vector<vector<bool>> vis(totalRows, vector<bool>(totalCols, false));
        queue<pair<pair<int,int>, int>> q;
        for(int i = 0; i < totalRows; i++){
            for(int j = 0; j < totalCols; j++){
                if(grid[i][j] == 0){
                    q.push({{i,j}, 0});
                }
            }
        }

        while(!q.empty()){
            int currRow = q.front().first.first;
            int currCol = q.front().first.second;
            int distance = q.front().second;

            q.pop();

            grid[currRow][currCol] = distance;

            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                    if(abs(deltaRow) == abs(deltaCol)) continue;

                    int newRow = currRow + deltaRow;
                    int newCol = currCol + deltaCol;

                    if(newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols
                    && vis[newRow][newCol] == false && grid[newRow][newCol] == INT_MAX)
                    {
                        vis[newRow][newCol] = true;
                        q.push({{newRow, newCol}, distance + 1});
                    }
                }
            }
        }
    }
};
