class Solution {
   public:
    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col,
             int prevCellVal) {
        vis[row][col] = true;

        int totalRows = heights.size();
        int totalCols = heights[0].size();

        for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
            for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
                if (abs(deltaRow) == abs(deltaCol)) continue;

                int newRow = row + deltaRow;
                int newCol = col + deltaCol;

                if (newRow >= 0 && newRow < totalRows && newCol >= 0 && newCol < totalCols &&
                    vis[newRow][newCol] == false && prevCellVal <= heights[newRow][newCol]) {
                    DFS(heights, vis, newRow, newCol, heights[newRow][newCol]);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;

        int totalRows = heights.size();
        int totalCols = heights[0].size();

        vector<vector<bool>> pacificVis(totalRows, vector<bool>(totalCols, false));
        vector<vector<bool>> atlanticVis(totalRows, vector<bool>(totalCols, false));

        for (int i = 0; i < totalCols; i++) {
            if (pacificVis[0][i] == false) {
                DFS(heights, pacificVis, 0, i, heights[0][i]);
            }
            if (atlanticVis[totalRows - 1][i] == false) {
                DFS(heights, atlanticVis, totalRows - 1, i, heights[totalRows - 1][i]);
            }
        }

        for (int i = 0; i < totalRows; i++) {
            if (pacificVis[i][0] == false) {
                DFS(heights, pacificVis, i, 0, heights[i][0]);
            }
            if (atlanticVis[i][totalCols - 1] == false) {
                DFS(heights, atlanticVis, i, totalCols - 1, heights[i][totalCols - 1]);
            }
        }

        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                if (pacificVis[i][j] == true && atlanticVis[i][j] == true) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
