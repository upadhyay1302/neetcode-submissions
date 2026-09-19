class Solution {
public:
    int solve(int n, vector<int>&DP){
        if(n == 0) return 0;
        if(DP[n] != -1) return DP[n];
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1 + solve(n - i *i, DP));
        }
        DP[n] = ans;
        return DP[n];
    }
    int numSquares(int n) {
        vector<int>DP(n + 1, -1);
        return solve(n, DP);
    }
};

//n , i can use 1 to n*n 

// 4  1, 2, 4