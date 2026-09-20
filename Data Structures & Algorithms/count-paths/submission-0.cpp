class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>>& DP){
        if(i == m - 1 && j == n - 1) return 1;

        if(i >=m || j >= n) return 0;

        if(DP[i][j] != -1) return DP[i][j];

        int ans = 0;

        int left = solve(i + 1, j, m, n, DP);
        int right = solve(i, j + 1, m, n, DP);
        ans = left + right;

        DP[i][j] = ans;

        return ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>DP(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m, n, DP);
    }
};

// m x n grid down or to the right
// m and n 
// grid[0][0] starting point
// grid[m-1][n-1] ending point
