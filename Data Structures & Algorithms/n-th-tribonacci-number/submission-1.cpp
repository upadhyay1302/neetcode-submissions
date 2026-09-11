class Solution {
public:
    int solve(int n, vector<int>&DP){
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(n == 2) return 1;

        if(DP[n] != -1) return DP[n];
        DP[n] = solve(n - 1, DP) + solve(n - 2, DP) + solve(n - 3, DP);
        return DP[n];
    }
    int tribonacci(int n) {
        vector<int> DP(n + 1, -1);
        return solve(n, DP);
    }
};