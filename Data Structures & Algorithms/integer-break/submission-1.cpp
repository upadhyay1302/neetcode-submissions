class Solution {
public:
    int solve(int n, vector<int>& DP){
        if(n == 1) return 1;

        if(DP[n] != -1) return DP[n];

        int ans = INT_MIN;

        for(int i = 1; i < n; i++){
            int prod = max(i * (n-i), i * solve(n - i, DP));
            ans = max(ans, prod);
        }
        DP[n] = ans;
        return DP[n];
    }
    int integerBreak(int n) {
        vector<int>DP(n + 1, -1);
        return solve(n, DP);
    }
};