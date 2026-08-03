class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount + 1, INT_MAX);
        ans[0] = 0;                     

        for (int i = 1; i < ans.size(); i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i && ans[i - coins[j]] != INT_MAX) {  
                    ans[i] = min(ans[i], 1 + ans[i - coins[j]]);
                }
            }
        }

        return ans.back() == INT_MAX ? -1 : ans.back();
    }
};