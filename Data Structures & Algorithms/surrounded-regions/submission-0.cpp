class Solution {
public:
    void DFS(int currRow, int currCol, vector<vector<bool>>& vis, vector<vector<char>>& board){
        vis[currRow][currCol] = true;

        int totalRows = board.size();
        int totalCols = board[0].size();

        for(int deltaRow = -1 ; deltaRow <= 1; deltaRow++){
            for(int deltaCol = -1; deltaCol <= 1; deltaCol++){

                if(abs(deltaRow) == abs(deltaCol)) continue;

                int newRow = currRow + deltaRow;
                int newCol = currCol + deltaCol;

                if(newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols && vis[newRow][newCol] == false && 
                    board[newRow][newCol]== 'O'){
                    DFS(newRow, newCol, vis, board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int totalRows = board.size();
        int totalCols = board[0].size();

        vector<vector<bool>> vis(totalRows, vector<bool>(totalCols, false));

        for(int i = 0; i < totalCols; i++){
            if(vis[0][i] == false && board[0][i] == 'O'){
                DFS(0, i, vis, board);
            }

            if(vis[totalRows - 1][i] == false && board[totalRows - 1][i] == 'O'){
                DFS(totalRows - 1, i, vis, board);
            }
        }

        for(int i = 0; i < totalRows; i++){
            if(vis[i][0] == false && board[i][0] == 'O'){
                DFS(i, 0, vis, board);
            }

            if(vis[i][totalCols - 1] == false && board[i][totalCols - 1] == 'O'){
                DFS(i, totalCols - 1, vis, board);
            }
        }


        for(int i = 0; i < totalRows; i++){
            for(int j = 0; j < totalCols; j++){
                if(vis[i][j] == false && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        // return board;
    }
};