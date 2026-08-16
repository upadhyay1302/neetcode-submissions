class Solution {
public:
    int solve(string& a, string& b, int i, int j){
        if(i >= a.length() || j >= b.length()) return 0;

        if(a[i] == b[j]) return 1 + solve(a, b, i + 1, j + 1);
        else return max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    }

    int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &DP){
        if(i >= a.length() || j >= b.length()) return 0;

        if(DP[i][j] != -1) return DP[i][j];

        if(a[i] == b[j]) DP[i][j] = 1 + solve(a, b, i + 1, j + 1);
        else DP[i][j] = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));

        return DP[i][j];
    }

    int solveTab(string& a, string& b){
        vector<vector<int>>DP(a.size() + 1, vector<int>(b.size() + 1,0));

        for(int i = a.length() - 1; i >= 0; i--){
            for(int j = b.length() - 1; j >= 0; j--){
                if(a[i] == b[j]) DP[i][j] = 1 + DP[i + 1][j + 1];
                else DP[i][j] = max(DP[i + 1][j], DP[i][j + 1]);
            }
        }
        return DP[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>DP(text1.size(), vector<int>(text2.size(),-1));

        // return solveMem(text1, text2, 0, 0, DP);
        return solveTab(text1, text2);
    }
};
