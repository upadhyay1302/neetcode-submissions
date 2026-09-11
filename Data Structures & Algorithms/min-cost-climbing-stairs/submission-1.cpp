class Solution {
public:
    int solve(vector<int>& cost, int i, vector<int>&DP){
        if(i >= cost.size()) return 0;

        if(DP[i] != -1) return DP[i];

        int oneStep = cost[i] + solve(cost, i + 1, DP);
        int twoStep = cost[i] + solve(cost, i + 2, DP);

        cout << oneStep << " " << twoStep << endl;

        DP[i] = min(oneStep, twoStep);
        return DP[i];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> DP(cost.size() + 1, -1);

        int ans1 = solve(cost, 0, DP);
        int ans2 = solve(cost, 1, DP);
        return min(ans1, ans2);
    }
};
