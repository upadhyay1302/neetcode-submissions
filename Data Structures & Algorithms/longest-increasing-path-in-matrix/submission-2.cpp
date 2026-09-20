class Solution {
public:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0, -1}, {0,1}};
    int solve(int i, int j, vector<vector<int>>& matrix, int prevVal, vector<vector<int>>&DP){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= prevVal){
            return 0;
        }
        if(DP[i][j] != -1) return DP[i][j];
        int ans = 0;
        for(auto d : directions){
            ans = max(ans, 1 + solve(i + d[0], j + d[1], matrix, matrix[i][j], DP));
        }
        DP[i][j] = ans;
        return DP[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        vector<vector<int>> DP(rows + 1, vector<int>(cols, -1));
        for(int i = 0; i < rows; i ++){
            for(int j = 0; j < cols; j++){
                ans = max(ans, solve(i, j, matrix, INT_MIN, DP));
            }
        }
        return ans;
    }
};
