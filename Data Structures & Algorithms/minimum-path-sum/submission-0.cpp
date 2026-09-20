class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&DP){
        if(i == m - 1 && j == n - 1) return grid[i][j];

        if(i >= m ||j >= n) return INT_MAX;

        if(DP[i][j] != -1) return DP[i][j];

        DP[i][j] =  grid[i][j] + min(solve(i + 1, j, m, n, grid, DP), solve(i, j + 1, m, n, grid, DP)); 
        return DP[i][j];


    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols
        int i = 0; // starter variable for rows
        int j = 0; //starter variable for cols;
        vector<vector<int>>DP(m + 1, vector<int>(n + 1, -1));
        return solve(i, j, m, n, grid, DP);
    }
};