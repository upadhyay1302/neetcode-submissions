class Solution {
public:
    int solve(int i, int buy, vector<int>&prices, vector<vector<int>>&DP){
        if(i >= prices.size()) return 0;
        if(DP[i][buy] != -1) return DP[i][buy];
        int ans = 0;
        if(buy){
            ans = max((-prices[i] + solve(i + 1, 0, prices, DP)), (0 + solve(i + 1, 1, prices, DP)));
        }
        else{
            ans = max((prices[i] + solve(i + 2, 1, prices, DP)), (0 + solve(i + 1, 0, prices, DP)));
        }
        DP[i][buy] = ans;
        return DP[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>DP(prices.size() + 1, vector<int>(2, -1));
        return solve(0, 1, prices, DP);
    }
};