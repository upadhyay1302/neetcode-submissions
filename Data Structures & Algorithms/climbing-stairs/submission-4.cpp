class Solution {
public:
    int solve(int n, vector<int>& DP){
        if(n == 0) return 1;

        if(n < 0) return 0;

        if(DP[n] != -1) return DP[n];

        int count = 0;

        for(int i = 1; i <= 2; i++){
            count += solve(n - i, DP);
        }

        DP[n] = count;
        return DP[n];
    }
    int climbStairs(int n) {
        vector<int> DP(n + 1, -1);
        return solve(n, DP);
    }
};
