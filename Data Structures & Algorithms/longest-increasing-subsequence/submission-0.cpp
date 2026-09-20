class Solution {
public:
    int solve(int i, int lastIndex, vector<int>&nums, vector<vector<int>>&DP){
        if(i >= nums.size()) return 0;

        if(DP[lastIndex + 1][i] != -1) return DP[lastIndex + 1][i];

        int ans = 0;
        int include = 0;

        if(lastIndex == -1 || nums[i]  > nums[lastIndex]){
            include = 1 + solve(i + 1, i, nums, DP);
        }

        int exclude = 0 + solve(i + 1, lastIndex, nums, DP);

        DP[lastIndex + 1][i] = max(include, exclude);
        return DP[lastIndex + 1][i];

    }
    int lengthOfLIS(vector<int>& nums) {
        int lastIndex = -1;
        //i = 0 to nums.size() => nums.size() + 1;
        // lastIndex goes from -1 to num.size()-1 =? nums.size() + 1;
        vector<vector<int>> DP(nums.size()+2, vector<int>(nums.size() + 1, -1));
        return solve(0, lastIndex, nums, DP);
    }
};
