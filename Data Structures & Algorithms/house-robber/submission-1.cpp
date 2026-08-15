class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& DP){
        if(i >= nums.size()) return 0;
        if(DP[i] != -1) return DP[i];
        int include = nums[i] + solve(nums, i + 2, DP);
        int exclude = 0 + solve(nums, i + 1, DP);

        DP[i] = max(include,exclude);
        return DP[i];
    }
    int rob(vector<int>& nums) {
        vector<int> DP(nums.size(), -1);
        return solve(nums, 0, DP);
    }
};
