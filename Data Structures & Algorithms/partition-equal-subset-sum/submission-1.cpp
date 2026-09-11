class Solution {
public:
    bool solveMem(vector<int>& nums, int target, int index, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(index >= nums.size()) return false;
        if(target < 0) return false;

        if(dp[target][index] != -1) return dp[target][index];

        int include = solveMem(nums, target - nums[index], index + 1, dp);
        int exclude = solveMem(nums, target, index + 1,dp);

        dp[target][index] = include || exclude;
        return dp[target][index];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for(int i = 0; i <nums.size(); i++){
            total = total + nums[i];
        }

        if(total % 2 != 0) return false;


        int target = total/2;
        int index = 0;

        cout << target;

        vector<vector<int>> dp(target+1,vector<int>(nums.size(),-1));
        bool ans = solveMem(nums, target, index,dp);

        return ans;
    }
};