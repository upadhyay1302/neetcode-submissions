class Solution {
public:
    int solve(vector<int>&nums, int startIndex, int endIndex, vector<int>& DP){
        if(startIndex > endIndex) return 0;

        if(DP[startIndex] != -1) return DP[startIndex];
        int include = nums[startIndex] + solve(nums, startIndex + 2, endIndex, DP);
        int exclude = 0 + solve(nums, startIndex + 1, endIndex, DP);

        DP[startIndex] = max(include, exclude);
        return DP[startIndex];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> DP1(nums.size() + 1, -1);
        vector<int> DP2(nums.size() + 1, -1);
        int ans1 = solve(nums, 0, nums.size()-2, DP1);
        int ans2 = solve(nums, 1, nums.size()-1, DP2);

        return max(ans1, ans2);
    }
};
