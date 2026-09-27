class Solution {
public:
    int solve(int amount, vector<int>&coins, int i, vector<vector<int>>&DP){
        if(amount == 0) return 1;

        if(amount < 0 || i >= coins.size()) return 0;

        if(DP[i][amount] != -1) return DP[i][amount];

        int include = solve(amount - coins[i], coins, i, DP);
        int exclude = solve(amount, coins , i + 1, DP);
        DP[i][amount] = include + exclude;
        return DP[i][amount];

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> DP(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(amount, coins, 0, DP);
    }
};
