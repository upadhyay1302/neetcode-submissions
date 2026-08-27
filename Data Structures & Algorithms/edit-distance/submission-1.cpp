class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& word1, string& word2, int i, int j) {
        if (i == word1.length()) return word2.length() - j;
        if (j == word2.length()) return word1.length() - i;

        if (dp[i][j] != -1) return dp[i][j];  

        int ans;
        if (word1[i] == word2[j]) {
            ans = solve(word1, word2, i + 1, j + 1);
        } else {
            int insertans  = 1 + solve(word1, word2, i, j + 1);
            int deleteans  = 1 + solve(word1, word2, i + 1, j);
            int replaceans = 1 + solve(word1, word2, i + 1, j + 1);
            ans = min({insertans, deleteans, replaceans});
        }

        return dp[i][j] = ans;  
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, 0, 0);
    }
};