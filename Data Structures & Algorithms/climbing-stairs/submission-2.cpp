class Solution {
public:
    // int solve(int n){
    //     if(n == 0) return 1;
    //     if(n < 0) return 0;

    //     int count = 0;
    //     for(int i = 1; i <= 2; i++){
    //         count = count + solve(n - i);
    //     }

    //     return count;

    // }
    int solveMem(int n, vector<int> &dp){
        if(n == 0) return 1;
        // if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        int count = 0;
        for(int i = 1; i <= 2; i++){
            count = count + solveMem(n - i, dp);
        }
        dp[n] = count;
        return dp[n];

    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solveMem(n, dp);
        
    }
};
