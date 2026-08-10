class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        int ans = 0;

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(totalRows, vector<int>(totalCols, 0));

        for(int i = 0; i < totalRows; i++){
            for(int j = 0; j < totalCols; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i , j}, 0});
                }
            }
        }

        while(!q.empty()){
            pair<pair<int,int>, int> node = q.front();
            q.pop();
            int currRow = node.first.first;
            int currCol = node.first.second;
            int time = node.second;

            ans = max(ans, time);
            
            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                    if(abs(deltaCol) == abs(deltaRow)) continue;
                    int newRow = currRow + deltaRow;
                    int newCol = currCol + deltaCol;

                    if(newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols
                        && vis[newRow][newCol] != 2 && grid[newRow][newCol] == 1)
                    {
                        vis[newRow][newCol] = 2;
                        q.push({{newRow, newCol}, time + 1});
                    }
                }
            }
        }

        for(int i = 0; i < totalRows; i++){
            for(int j = 0; j < totalCols; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};